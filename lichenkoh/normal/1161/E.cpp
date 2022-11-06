#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<pii> vpii;typedef vector<int> vi;typedef vector<vi> vvi;

int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

class UnionFind {
  typedef bool UFTYPE;
public:
  UFTYPE ufIdentity = -1;
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    return x||y;
  }
  inline UFTYPE getInitialValue(int x) {
    return false;
  }
  vi ufParent;
  vi rank;
  vector<UFTYPE> ufData;
  vvi child;
  void init(int n) {
    ufParent.resize(n+1);ufData.resize(n+1);rank.resize(n+1);child.resize(n+1);
    for (int x=0;x<=n;x++) {
      ufParent[x]=x;
      ufData[x]=getInitialValue(x);
      rank[x]=1;
      child[x].PB(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]+=rank[xr];
    ufParent[xr] = yr;
    ufData[yr]=combine(ufData[xr],ufData[yr]);
    for (auto &w:child[xr]) {
      child[yr].PB(w);
    }
    child[xr].clear();
  }
  UFTYPE getDataForPos(int x) {
    return ufData[ffind(x)];
  }
};
template<typename T> void makeunique(vector<T> &vec) {
  sort( vec.begin(), vec.end() );
  vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
}
vi unpack(pii x) {
  vi v(2); v[0]=x.fst,v[1]=x.snd; return v;
}
vpii askBuf;
void addask(int x, int y) {
  askBuf.PB(MP(x,y));
}
vector<bool> _ask() {
  if (askBuf.size()==0) {
    vector<bool> emp; return emp;
  }
  cout<<"Q "<<askBuf.size();
  for (auto &w:askBuf) cout<<" "<<w.fst<<" "<<w.snd;
  cout<<endl<<flush; cout.flush();
  string s; cin>>s;
  if (s=="-1") exit(0);
  assert(s.length()==askBuf.size());
  vector<bool> v(s.length());
  for (int i=0;i<s.length();i++) v[i]=(s[i]=='1');
  return v;
}
pair<vpii,vpii> askAndSplit() {
  auto ans=_ask();
  vpii a,b;
  for (int i=0;i<ans.size();i++) {
    if (ans[i]) a.PB(askBuf[i]);
    else b.PB(askBuf[i]);
  }
  askBuf.clear();
  return MP(a,b);
}
vector<bool> ask() {
  auto ans=_ask();
  askBuf.clear();
  return ans;
}
void go() {
  askBuf.clear();
  int n; cin>>n; if (n==-1) exit(0);
  UnionFind uf;
  uf.init(2*n+1);
  vector<pii> a[2];
  for (int x=1;x<=n;x++) a[0].PB(MP(-1,x));
  int cur=0,nxt=1;
  vector<pii> oppPair;
  for (int t=0;t<3;t++) {
    sort(a[cur].begin(),a[cur].end());
    {
      int asz=a[cur].size();
      int head=0,tail=1;
      set<int> seen;
      while(head<asz&&tail<asz) {
        auto &v=uf.child[uf.ffind(a[cur][head].snd)];
        assert(v.size()==-a[cur][head].fst);
        chkmax(tail,head+1);
        if (tail>=asz) break;
        for (auto &y:v) {
          if (seen.count(y)) continue;
          seen.insert(y);
          seen.insert(a[cur][tail].snd);
          addask(y,a[cur][tail].snd);
          tail++;
          if (tail>=asz) break;
        }
        head++;
      }
    }
    {
      pair<vpii,vpii> result=askAndSplit();
      for (auto &w:result.fst) {
        int x=w.fst,y=w.snd;
        uf.funion(x,y);
      }
      for (auto &w:result.snd) {
        int x=uf.ffind(w.fst),y=uf.ffind(w.snd);
        if ((!uf.getDataForPos(x))&&(!uf.getDataForPos(y))) {
          uf.ufData[x]=true;
          uf.ufData[y]=true;
          oppPair.PB(MP(x,y));
        }
      }
    }
    {
      a[nxt].clear();
      for (auto &w:a[cur]) {
        int x=uf.ffind(w.snd);
        if (!uf.getDataForPos(x)) {
          a[nxt].PB(MP(-uf.child[x].size(),x));
        }
      }
      makeunique(a[nxt]);
    }
    swap(cur,nxt);
  }
  int ops=oppPair.size();
  if (ops==0) {
    assert(a[cur].size()==1);
    cout<<"A 0 0 "<<n<<endl<<endl<<endl;
    for (int x=1;x<=n;x++) {cout<<x;if(x!=n)cout<<" ";}
    cout<<endl<<flush; cout.flush(); return;
  }
  assert(a[cur].size()<=1);
  vi table[2][2]; for (int x=0;x<2;x++) for (int y=0;y<2;y++) table[x][y].resize(ops,-1);
  vi extra(2,-1);
  for (int bx=0;bx<2;bx++) {
    for (int by=0;by<2;by++) {
      //printf("bx:%d by:%d\n",bx,by);
      int cx=bx,cy=by;
      for (int i=0;i<ops-1;i++) {
        vi x=unpack(oppPair[i]),y=unpack(oppPair[i+1]);
        addask(x[cx],y[cy]);
        if (cx==cy) {cx^=1; cy^=1;}
      }
      if (by==0&&a[cur].size()) {
        vi x=unpack(oppPair[0]);
        addask(x[bx^1],a[cur][0].snd);
      }
      vector<bool> res=ask();
      cx=bx,cy=by;
      for (int op=0;op<ops-1;op++) {
        vi x=unpack(oppPair[op]),y=unpack(oppPair[op+1]);
        table[cx][cy][op]=res[op]?1:0;
        if (cx==cy) {cx^=1; cy^=1;}
      }
      if (by==0&&a[cur].size()) {
        vi x=unpack(oppPair[0]);
        extra[bx^1]=res.back()?1:0;
      }
    }
  }
  int BASE=n+1;
  if (a[cur].size()) {
    vi x=unpack(oppPair[0]); bool found=false;
    for (int b=0;b<2;b++) if (extra[b]) {uf.funion(a[cur][0].snd,x[b]); found=true;}
    if (!found) uf.funion(a[cur][0].snd,BASE+0);
  }
  for (int op=0;op<ops-1;op++) {
    vi x=unpack(oppPair[op]),y=unpack(oppPair[op+1]);
    for (int xi=0;xi<2;xi++) {
      bool found=false;
      for (int yi=0;yi<2;yi++) {
        //printf("op:%d xi:%d yi:%d t:%d\n",op,xi,yi,table[xi][yi][op]);
        assert(table[xi][yi][op]!=-1);
        if (table[xi][yi][op]) {uf.funion(x[xi],y[yi]); found=true;}
      }
      if (!found) {
        //printf("Union:%d %d\n",x[xi],BASE+op+1);
        uf.funion(x[xi],BASE+op+1);
      }
    }
    set<int> s; for (int k=0;k<2;k++) s.insert(uf.ffind(y[k])); s.insert(uf.ffind(BASE+op+1));
    assert(s.size()==3);
    //for (auto &w:s) printf("%d ",w); printf(" end orig s\n");
    for (int k=0;k<2;k++) s.erase(uf.ffind(x[k]));
    //for (auto &w:s) printf("%d ",w); printf(" end new s\n");
    assert(s.size()==1);
    uf.funion(BASE+op,*(s.begin()));
  }
  set<int> sfinal;
  for (int x=1;x<=BASE+ops-1;x++) {
    //printf("x:%d ff:%d\n",x,uf.ffind(x));
    sfinal.insert(uf.ffind(x));
  }
  assert(sfinal.size()==3);
  vvi vans;
  for (auto &x:sfinal) {
    vi ans;
    for (auto &w:uf.child[x]) {
      if (1<=w&&w<=n) ans.PB(w);
    }
    vans.PB(ans);
  }
  cout<<"A"; for (auto &w:vans) cout<<" "<<w.size();
  cout<<endl;
  for (auto &w:vans) {
    int wsz=w.size();
    for (int i=0;i<wsz;i++) {
      cout<<w[i]; if (i!=wsz-1) cout<<" ";
    }
    cout<<endl;
  }
  cout<<flush; cout.flush();
}
int main() 
{
  int t; cin>>t; for (int i=0;i<t;i++) go();
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}