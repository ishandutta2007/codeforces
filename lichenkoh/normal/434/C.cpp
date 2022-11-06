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
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

const int AC_SIGMA=26;
struct node{
    int ch[AC_SIGMA],fail,cost;

    node(){
        fail = cost = 0;
        for (int i=0;i<AC_SIGMA;i++)  ch[i] = 0;
    }
};
const int MAXS=204;
struct AhoCorasick{
  node Tree[MAXS];
  int avail;
  int dpcost[MAXS];
    AhoCorasick(){ avail = 1; Tree[1] = node(); memset(dpcost,-1,sizeof dpcost);}

    void insert(vector<int> &a, int cost){
        int root = 1;
        int l=a.size();
        for (int i=0;i<l;i++){
            int id = a[i];

            if (!Tree[root].ch[id]){
                Tree[root].ch[id] = ++avail;
                Tree[avail] = node();
            }

            root = Tree[root].ch[id];
        }

        Tree[root].cost += cost;
    }

    void bfs(){
        queue<int>q;
        q.push(1);

        for (int i=0;i<AC_SIGMA;i++)      Tree[0].ch[i] = 1;

        while(!q.empty()){
            int u = q.front();q.pop();

            for (int i=0;i<AC_SIGMA;i++){
                int v = Tree[u].ch[i];

                if (v){
                    Tree[v].fail = Tree[ Tree[u].fail ].ch[i];
                    q.push(v);
                }

                else Tree[u].ch[i] = Tree[ Tree[u].fail ].ch[i];
            }
        }
    }

    node& operator[](int idx){
        return Tree[idx];
    }
    int getCost(int state) {
      int dpval=dpcost[state];
      if (dpval!=-1) return dpval;
      int ans=0;
      if (state) ans=Tree[state].cost+getCost(Tree[state].fail);
      return dpcost[state]=ans;
    }
    pair<int,int> nextState(int state, int nextChar) {
      int newstate = Tree[state].ch[nextChar];
      int cost=getCost(newstate);
      return MP(newstate,cost);
    }
};


vector<int> readi() {
  int len; cin>>len;
  vector<int> ans;
  for (int i=0;i<len;i++) {
    int x; cin>>x; ans.PB(x);
  }
  return ans;
}
const int me=204,ms=2, MAXC=502;
int dp[me][2][MAXS][2][MAXC];
int md;
vector<int> lim;
bool eqok;
const int LS=0,EQ=1,GR=2;
int trans(int cur, int limd, int s) {
  if (s==EQ) {
    if (cur<limd) return LS;
    else if (cur==limd) return EQ;
    else return GR;
  }
  else return s;
}
AhoCorasick AC;
int n,m,k;
int solve(int e, int s, int aho, int pos, int cost) {
  if (e==lim.size()) {
    if (s==LS) return 1;
    if (s==EQ&&eqok) return 1;
    return 0;
  }
  int dpval=dp[e][s][aho][pos][cost];
  if (dpval!=-1) return dpval;
  ll ans=0;
  for (int d=0;d<m;d++) {
    int ns=trans(d,lim[e],s);
    int npos=pos;
    if (d) npos=1;
    int naho=aho;
    int ncost=cost;
    if (npos) {
      auto got=AC.nextState(aho, d);
      naho=got.fst;
      ncost+=got.snd;
    }
    if (ncost<=k&&ns!=GR) ans+=solve(e+1,ns,naho,npos,ncost);
  }
  return dp[e][s][aho][pos][cost]=ans%MOD;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>k;
  md=m;
  vector<int> l=readi(),r=readi();
  for (int i=0;i<n;i++) {
    vector<int> got=readi();
    int val;cin>>val;
    AC.insert(got,val);
  }
  AC.bfs();
  lim=r;
  eqok=1;AhoCorasick AC;
  memset(dp,-1,sizeof dp);
  int R=solve(0,EQ,1,0,0);
  lim=l;
  eqok=0;
  memset(dp,-1,sizeof dp);
  int L=solve(0,EQ,1,0,0);
  //printf("L:%d R:%d\n",L,R);
  int ans=(R-L+MOD)%MOD;
  printf("%d\n",ans);
}