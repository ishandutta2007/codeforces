#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

inline void OPTIMIZE(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
}

//end of macro

const ll MOD = 1e9 + 7;
inline ll addmod(ll a, ll b){
	return (a+b)%MOD;
}
inline ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}

const int N = 2005;

int d,n;
int v[N];
vii sorter;
vi lst[N];
bool vis[N];

int dfs(int now, int par, int lim){
	int ret = 1;
	FOR(i,lst[now].size()){
		int to = lst[now][i];
		if(to == par)continue;
		if(vis[to])continue;
		if(v[to] > lim)continue;
		
		ret = mulmod(ret, dfs(to, now, lim)+1);
	}
	return ret;
}

int main(){
    OPTIMIZE();
	
	cin>>d>>n;
	REP(i,1,n){
		cin>>v[i];
		sorter.pb(mp(v[i], i));
	}
	sort(sorter.begin(), sorter.end());
	REP(i,1,n-1){
		int a,b;
		cin>>a>>b;
		lst[a].pb(b);
		lst[b].pb(a);
	}
	
	int ans = 0;
	FOR(i,sorter.size()){
		//printf("dfs %d %d\n",sorter[i].S, dfs(sorter[i].S, -1, sorter[i].F + d));
		ans = addmod(ans, dfs(sorter[i].S, -1, sorter[i].F + d));
		vis[sorter[i].S] = true;
	}
	cout << ans << endl;
	
    return 0;
}