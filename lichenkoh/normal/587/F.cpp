#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

// Linear Suffix Array O(N)

// String index from 0
// Usage:
//  string s;
//  DC3Algorithm dc3;
//  dc3.Construct(s);
//  Now we can use dc3.GetSA() and dc3.GetLCP()
// SA and LCP is 0-indexed
// First entry of LCP is always 0
// LCP[i]=Longest common prefix between LCP[i-1] and LCP[i]
// After building SparseTabe, query(left+1,right) to query LCP of SA[left],SA[right]

#define MAXN 200004 // >= 256
class DC3Algorithm {
private: 
    int AN;
    int A[3 * MAXN + 100];
    int cnt[MAXN + 1]; 
    int SA[MAXN + 1];

    void radix_pass(int* A, int AN, int* R, int RN, int* D) {
        memset(cnt, 0, sizeof(int) * (AN + 1));
        int* C = cnt + 1;
        for (int i = 0; i < RN; i++) ++C[A[R[i]]];
        for (int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);
        for (int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];
    }

    void suffix_array(int* A, int AN) {
        if (!AN) 
            SA[0] = 0;
        else if (AN == 1) {
            SA[0] = 1;
            SA[1] = 0;
            return;
        }
        
        int RN = 0;
        int* SUBA = A + AN + 2;
        int* R = SUBA + AN + 2;
        for (int i = 1; i < AN; i += 3) SUBA[RN++] = i;
        for (int i = 2; i < AN; i += 3) SUBA[RN++] = i;
        A[AN + 1] = A[AN] = -1;
        radix_pass(A + 2, AN - 2, SUBA, RN, R);
        radix_pass(A + 1, AN - 1, R, RN, SUBA);
        radix_pass(A + 0, AN - 0, SUBA, RN, R);

        int resfix, resmul, v;
        if (AN % 3 == 1) {
            resfix = 1;
            resmul = RN >> 1;
        }
        else {
            resfix = 2;
            resmul = RN + 1 >> 1;
        }
        for (int i = v = 0; i < RN; i++) {
            v += i && (A[R[i - 1] + 0] != A[R[i] + 0] || A[R[i - 1] + 1] != A[R[i] + 1] || A[R[i - 1] + 2] != A[R[i] + 2]);
            SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul] = v;
        }

        if (v + 1 != RN) {
            suffix_array(SUBA, RN);
            SA[0] = AN;
            for (int i = 1; i <= RN; i++) 
                SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) : 3 * (SA[i] - resmul) + resfix;
        }
        else {
            SA[0] = AN;
            memcpy(SA + 1, R, sizeof(int) * RN);
        }

        int NMN = RN; 
        for (int i = RN = 0; i <= NMN; i++) 
            if (SA[i] % 3 == 1) 
                SUBA[RN++] = SA[i] - 1;
        
        radix_pass(A, AN, SUBA, RN, R);

        for (int i = 0; i <= NMN; i++) 
            SUBA[SA[i]] = i;

        int ii = RN - 1;
        int jj = NMN;
        int pos;
        for (pos = AN; ii >= 0; pos--) {
            int i = R[ii];
            int j = SA[jj];
            int v = A[i] - A[j];
            if (!v) 
                if (j % 3 == 1) 
                    v = SUBA[i + 1] - SUBA[j + 1];
                else {
                    v = A[i + 1] - A[j + 1];
                    if (!v) v = SUBA[i + 2] - SUBA[j + 2];
                }            
            SA[pos] = v < 0 ? SA[jj--] : R[ii--];
        }
    }

    void prep_string(string s) {
        int v = 0;
        AN = s.length();
        memset(cnt, 0, 256 * sizeof(int));
        for (int i = 0; i < AN; i++) cnt[s[i]]++;
        for (int i = 0; i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;
        for (int i = 0; i < AN; i++) A[i] = cnt[s[i]];
    }

    int REVSA[MAXN + 1];
    void compute_reverse_sa() {
        for (int i = 0; i <= AN; i++) REVSA[SA[i]] = i;
    }

    int LCP[MAXN + 1];
    void compute_lcp() {
        int len = 0;
        for (int i = 0; i < AN; i++, len = max(0, len - 1)) {
            int s = REVSA[i];
            int j = SA[s - 1];
            for (; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
            LCP[s] = len;
        }
    }
    
public:
    
    void Construct(string s) {
        prep_string(s.c_str());
        suffix_array(A, AN);
        compute_reverse_sa();
        compute_lcp();
    }
    
    vector<int> GetSA() {
        vector<int> ret; ret.clear();
        for (int i = 1; i <= AN; i++)
            ret.push_back(SA[i]);
        return ret;
    }
    
    vector<int> GetLCP() {
        vector<int> ret; ret.clear();
        for (int i = 1; i <= AN; i++)
            ret.push_back(LCP[i]);
        return ret;
    }
};


class RmqSparseTable {

  int* logTable;
  int** rmq;
  vector<int> a;
  int n;
  public:
  RmqSparseTable(vector<int> _a) {
    a=_a;
    n=_a.size();

    logTable = new int[n + 1];
    fill(logTable,logTable+n+1,0);
    for (int i = 2; i <= n; i++)
      logTable[i] = logTable[i >> 1] + 1;

    rmq = new int*[logTable[n] + 1];
    for (int i=0;i<logTable[n] + 1;i++) {
      rmq[i]=new int[n];
    }
    for (int i = 0; i < n; ++i)
      rmq[0][i] = i;

    for (int k = 1; (1 << k) < n; ++k) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        int x = rmq[k - 1][i];
        int y = rmq[k - 1][i + (1 << k - 1)];
        rmq[k][i] = a[x] <= a[y] ? x : y;
      }
    }
  }

  int minPos(int i, int j) {
    int k = logTable[j - i];
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? x : y;
  }
  int minVal(int i, int j) {
    if (i>j) return INF;
    int k = logTable[j - i];
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? a[x] : a[y];
  }
};


const char TERM='{';
const int mn=100002;
const int LIM=825; // 1e5**(7./12.)
const int SMALL=(mn+LIM-1)/LIM;
//const int SMALL=0;

vector<int> root2other[mn];

string s[mn];
int vslen[mn];
char tmp[mn];
map<int,int, greater<int> > f[mn];

vector<pii> vstart[mn];
ll vans[mn];
int getr(vector<pii> &a, int key) {
  int imin=0,imax=a.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (a[imid].fst<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
int binsearch(vector<int> &a, int key) {
  int imin=0,imax=a.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (a[imid]<=key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

int p[mn];
void finit(int n) {
  for (int x=0;x<n;x++) p[x]=x;
}
int ffind(int x) {
  if (p[x] != x) {
    p[x] = ffind(p[x]);
  }
  return p[x];
}
void funion(int x, int y) {
  if (rand()&1) swap(x,y); 
  int xr = ffind(x);
  int yr = ffind(y);
  p[xr] = yr;
}

int sabase2idx[2*mn];
int sstart[mn];
vector<int> vquery[mn];
vector<int> rootarridxtable[mn];
int vl[mn],vr[mn];
int invSA[2*mn];
int ps[mn];
bool cmp(int x, int y) {
  return invSA[sstart[x]]<invSA[sstart[y]];
}
int main()
{
  
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n,q; scanf("%d %d\n",&n,&q);
  int sumlen=0;
  for (int i=0;i<n;i++) {
    scanf("%s\n",tmp);
    s[i]=string(tmp);
    int slen=s[i].length();
    vslen[i]=slen;
    sumlen+=slen+1;
  }
  string all; all.resize(sumlen);
  int sidx=0;
  for (int i=0;i<n;i++) {
    int slen=vslen[i];
    sstart[i]=sidx;
    for (int j=0;j<slen;j++) {
      all[sidx++]=s[i][j];
    }
    all[sidx++]=TERM;
  }
  DC3Algorithm dc3;
  dc3.Construct(all);

  vector<int> SA=dc3.GetSA();
  for (int i=0;i<SA.size();i++) invSA[SA[i]]=i;
  vector<int> LCP=dc3.GetLCP();
  //printf("%s\n\n",all.c_str());
  //for (int i=0;i<SA.size();i++) {
  //  auto w=SA[i];
  //  printf("%d: %s\n",i,all.substr(w,all.length()-w).c_str());
  //}
  //printf("\n");
  //for (auto &w:SA) printf("%d ",w); printf("\n");
  //for (auto &w:LCP) printf("%d ",w); printf("\n");
  {
    int sidx=0;
    for (int i=0;i<n;i++) {
      int slen=vslen[i];
      vstart[slen].PB(MP(invSA[sidx],i));
      //printf("i:%d sidx:%d invSA:%d slen:%d\n",i,sidx,invSA[sidx],slen);
      sidx+=slen+1;
    }
  }
  for (int len=0;len<mn;len++) if(vstart[len].size()) sort(vstart[len].begin(),vstart[len].end());
  RmqSparseTable ST=RmqSparseTable(LCP);
  set<int> setlen; for (int i=0;i<n;i++) setlen.insert(vslen[i]);
  vector<int> vsetlen; for (auto &w:setlen) vsetlen.PB(w);
  for (int i=0;i<n;i++) {
    int sabase=invSA[sstart[i]];
    sabase2idx[sabase]=i;
  }
  finit(n);
  for (int i=0;i<n;i++) {
    ps[i]=i;
  }
  sort(ps,ps+n,cmp);
  for (int i=0;i<n-1;i++) {
    int l=invSA[sstart[ps[i]]];
    int r=invSA[sstart[ps[i+1]]];
    //printf("l:%d r:%d ps[i]:%d ps[i+1]:%d\n",l,r,ps[i],ps[i+1]);
    if (l>r) swap(l,r);
    if (ST.minVal(l+1,r)>max(vslen[ps[i]],vslen[ps[i+1]])) {
      funion(ps[i],ps[i+1]);
    }
  }

  for (int x=0;x<n;x++) {
    int root=ffind(x);
    //printf("root:%d x:%d\n",root,x);
    root2other[root].PB(x);
  }
  for (int root=0;root<n;root++) {
    if (root2other[root].size()>=SMALL) {
      for (auto &other:root2other[root]) {
        rootarridxtable[root].PB(other);
      }
    }
  }
  for (int qi=0;qi<q;qi++) {
    int l,r,k; scanf("%d %d %d\n",&l,&r,&k);
    --l; --r; --k;
    vl[qi]=l;vr[qi]=r;
    vquery[k].PB(qi);
  }
  for (int k=0;k<n;k++) {
    if (vquery[k].size()==0) continue;
    map<int,int,greater<int> > f;
    vector<int> vrootarridx;
    int slen=vslen[k];
    for (int pos=0;pos<slen;pos++) {
      int baseidx=sstart[k]+pos;
      int sabase=invSA[baseidx];
      for (auto len:vsetlen) {
        if (pos+len>slen) break;
        int candres=getr(vstart[len],sabase);
        //printf("pos:%d sabase:%d len:%d candres:%d\n",pos,sabase,len);
        //for (auto &w:vstart[len]) printf("(%d,%d) ",w.fst,w.snd);
        //printf("\n");
        for (int cand=candres-1;cand<=candres;cand++) {
          if (!(0<=cand&&cand<vstart[len].size())) continue;
          auto got=vstart[len][cand];
          int ridx=got.snd;
          //printf("pos:%d sabase:%d k:%d ridx:%d len:%d\n",pos,sabase,k,ridx,len);
          //assert(len==vslen[ridx]);
          int lef=sabase,right=got.fst;
          if (lef>right) swap(lef,right);
          //printf("pos:%d sabase:%d lef:%d right:%d. ST:%d\n",pos,sabase,lef,right,ST.minVal(lef+1,right));
          if (lef==right||ST.minVal(lef+1,right)>=len) {
            int root=ffind(ridx);
            //printf("k:%d ridx:%d root:%d\n",k,ridx,root);
            if (root2other[root].size()>=SMALL) {
              vrootarridx.PB(root);
            }
            else {
              for (auto &other:root2other[root]) {
                //printf("other:%d\n",other);
                f[other]++;
              }
            }
            break;
          }
        }
      }
    }
    vector<pii> compressed;
    int sz=vrootarridx.size();
    if (sz>0){
      sort(vrootarridx.begin(),vrootarridx.end());
      int cnt=1;
      for (int i=1;i<sz;i++) {
        if (vrootarridx[i]!=vrootarridx[i-1]) {
          compressed.PB(MP(vrootarridx[i-1],cnt));
          cnt=1;
        }
        else cnt++;
      }
      compressed.PB(MP(vrootarridx[sz-1],cnt));
    }
    int prev=0;
    for (auto it=f.rbegin();it!=f.rend();++it) {
      it->snd+=prev;
      prev=it->snd;
    }
    for (auto &qi:vquery[k]){
      int l=vl[qi],r=vr[qi];
      auto lit=f.lower_bound(l-1);
      auto rit=f.lower_bound(r);
      int R=((rit==f.end())?0:rit->snd);
      int L=((lit==f.end())?0:lit->snd);
      //printf("qi:%d L:%d R:%d\n",qi,L,R);
      ll ans=R-L;
      for (auto &rootcnt:compressed) {
        int root=rootcnt.fst;
        int cnt=rootcnt.snd;
        vector<int> &a=rootarridxtable[root];
        int cl=binsearch(a,l-1);
        int cr=binsearch(a,r);
        //printf("root:%d cl:%d cr:%d cnt:%d\n",root,cl,cr,cnt);
        ans+=(cr-cl)*(ll)cnt;
      }
      vans[qi]=ans;
    }
  }
  for (int qi=0;qi<q;qi++) {
    printf("%lld\n",vans[qi]);
  }
}