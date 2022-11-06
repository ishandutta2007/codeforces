#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
const int mn=50002;
int vp[mn];
int vval[mn],vnext[mn];
int n,start,want;

void query(int i) {
  printf("? %d\n",i);
  fflush(stdout);
  int val,next; scanf("%d%d",&val,&next);
  vval[i]=val; vnext[i]=next;
}
void output(int ans) {
  printf("! %d\n",ans);
  fflush(stdout);
  exit(0);
}

int _val[mn],_ans;
/*void query(int i) {
  vval[i]=_val[i]; 
  if (i>1) vnext[i]=i-1;
  else vnext[i]=-1;
  //printf("? %d val:%d nxt:%d\n",i,vval[i],vnext[i]);
}
void output(int ans) {
  //printf("! %d. _ans:%d\n",ans,_ans);
  assert(ans==_ans);
}*/

void go() {
  memset(vnext,0,sizeof vnext);
  int s=min(n,999);
  for (int x=0;x<n;x++) vp[x]=x+1;
  mt19937 mt_rand(clock());
  for (int i=0;i<s;i++) {
    swap(vp[i],vp[mt_rand()%n]);
  }
  bool hasstart=false;
  for (int i=0;i<s;i++) {
    if (vp[i]==start) hasstart=true;
    query(vp[i]);
  }
  if (!hasstart) {
    query(start);
    vp[s++]=start;
  }
  pii best=MP(-1,-1);
  for (int i=0;i<s;i++) {
    int pos=vp[i];
    int val=vval[pos];
    //printf("pos:%d val:%d want:%d\n",pos,val,want);
    if (val<=want) chkmax(best,MP(val,pos));
  }
  //printf("best:%d %d\n",best.fst,best.snd);
  if (best.fst==-1) {
    if (vval[start]>=want) output(vval[start]);
    else output(-1);
    return;
  }
  int pos=best.snd;
  for (int i=0;i<1999-s;i++) {
    if (vnext[pos]==0) query(pos);
    if (vval[pos]>=want) {output(vval[pos]); return;}
    int next=vnext[pos];
    if (next==-1) {output(-1); return;}
    pos=next;
  }
  output(-1);
  return;
}
void test() {
  srand(clock());
  n=50000;start=n;
  for (int i=1;i<=n;i++) _val[i]=rand();
  sort(_val+1,_val+n+1,greater<int>());
  want=rand();
  _ans=-1;
  //for (int i=n;i>=1;i--) printf("%d,",_val[i]);
  for (int i=n;i>=1;i--) {
    if (_val[i]>=want) {
      _ans=_val[i];
      break;
    }
  }
  printf("want:%d val:%d\n",want,_ans);
  go();
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //for (int i=0;i<1000;i++) test();
  scanf("%d%d%d",&n,&start,&want);
  go();
}