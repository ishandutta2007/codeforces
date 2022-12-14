#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN (2*131072)

struct DP{//(+,max)
  int sum[MAXN*2+7], ma[MAXN*2+7];
  DP(){CLR(sum); CLR(ma);}
  void add(int l,int r,int w,int ll=1,int rr=MAXN,int x=1){
	//	if(x == 1) cout << "add " << l << " " << r << " " << w << endl;
    if(rr < l || r < ll) return;
    if(l <= ll && rr <= r){
      ma[x]+=w;
      sum[x] = (ma[x] ? (rr-ll+1) : (x < MAXN ? sum[2*x]+sum[2*x+1] : 0));
      return;
    }
    add(l,r,w,ll,(ll+rr)/2,2*x);
    add(l,r,w,(ll+rr+1)/2,rr,2*x+1);
    sum[x] = (ma[x] ? (rr-ll+1) : (x < MAXN ? sum[2*x]+sum[2*x+1] : 0));
  }
};

DP dp;

int a,b,n,m,pre[MAXN+7],post[MAXN+7],c,res[MAXN+7];
VI G[MAXN+7],what[MAXN+7];

void dfs(int x,int o) {
	//cout << "dfs " << x << " " << o << endl;
	pre[x] = ++c;
	FORE(i,G[x]) if(*i != o)
		dfs(*i, x);
	post[x] = ++c;
}

void go(int x,int o) {
	FORE(i,what[x])
		dp.add(pre[*i], post[*i], 1);
//	cout << "take " << x << endl;
	res[x] = dp.sum[1]/2;
	FORE(i,G[x]) if(*i != o)
		go(*i, x);
	FORE(i,what[x])
		dp.add(pre[*i], post[*i], -1);
}

int main(){
	ios_base::sync_with_stdio(false);
	//in
	cin >> n >> m;
	REP(i,n-1) {
		cin >> a >> b;
		G[a].PB(b);
		G[b].PB(a);
	}
	REP(i,m) {
		cin >> a >> b;
		what[a].PB(a);
		what[b].PB(a);
		what[a].PB(b);
		what[b].PB(b);
	}
	//sol
	dfs(1,1);
//	FOR(i,1,n) cout << pre[i] << " " << post[i] << endl;
	go(1,1);
	//out
	FOR(i,1,n) cout << (res[i] > 0 ? res[i]-1 : res[i]) << " ";
	cout << endl;
	return 0;
}