#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxv = 100001 * 51 + 10;

int oth[maxv];
int lst[maxv];
int nxt[maxv];
int en;

char open[100010][52];
int n, m, d;

int V;

int stk[maxv], top;
bool onstk[maxv];

int idx[maxv];
int low[maxv];
int nt;

int myc[maxv];
int cn;

int nxtmem[maxv];
int lstm[maxv];

void dfs(int x){
	idx[x] = low[x] = ++nt;
	stk[top++]=x; onstk[x]=1;
	for(int ep=lst[x]; ep; ep=nxt[ep]){
		int y=oth[ep];
		if(!idx[y]){
			dfs(y);
			low[x] = min(low[x], low[y]);
		} else if(onstk[y]) low[x] = min(low[x], idx[y]);
	}

	if(idx[x] == low[x]){
		++cn;
		int lstmem = -1;
		for(;top--;){
			int a=stk[top];
			onstk[a]=0;
			myc[a] = cn;

			nxtmem[a] = lstmem;
			lstmem = a;
			lstm[cn] = a;

			if(a == x) break;
		}
	}
}

int dp[maxv];
bool cvis[maxv];

int f(int x){
	if(cvis[x]) return dp[x];
	cvis[x] = 1;
	for(int m=lstm[x]; m>=0; m=nxtmem[m]) for(int ep=lst[m]; ep; ep=nxt[ep]){
		int y=oth[ep];
		if(myc[y] != x) dp[x] = max(dp[x], f(myc[y]));
	}
	set<int> op;
	for(int m=lstm[x]; m>=0; m=nxtmem[m]){
		int v=m/d, day=m%d;
		if(open[v][day] == '1'){
			op.insert(v);
		}
	}
	dp[x] += op.size();
	return dp[x];
}

int main()
{
	cppio();
	cin >> n >> m >> d;
	V = n*d;

	rrep(i, m){
		int a, b; cin >> a >> b;
		--a; --b;
		rep(da, d){
			int db = (da+1)%d;
			int S = a*d+da, T = b*d+db;
			int l = lst[S];
			lst[S] = ++en;
			oth[en] = T;
			nxt[en] = l;
		}
	}

	rep(i, n) cin >> open[i];

	rep(v, V) if(!idx[v]) dfs(v);

	cout << f(myc[0]) << endl;

	return 0;
}