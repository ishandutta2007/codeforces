//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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

//end of macro

const int N = 2e5 + 5;

int n;
vector<pii>lst[N]; // to, weight, power
int a[N], b[N], w[N], p[N];

ll curw[N];
ll minw[N];
ll maxred[N];
ll red[N];
void dfs(int now, int par){
	int tp;
	FOR(i,lst[now].size()){
		int to = lst[now][i].F;
		if(to == par){
			tp = i;
			continue;
		}
		dfs(to, now);
		curw[now] += curw[to];
		minw[now] += minw[to];
	}
	if(now == 1)return;
	ll wn = w[lst[now][tp].S];
	ll pn = p[lst[now][tp].S];
	maxred[now] = min(wn-1, pn - minw[now]);
	if(maxred[now] >= 0){
		red[now] = max(0LL, curw[now] - pn);
		curw[now] = min(curw[now], pn) + wn;
		minw[now] += wn - maxred[now];
	}
}

ll pfred[N];
void dfs2(int now, int par){
	pfred[now] = red[now];
	FOR(i,lst[now].size()){
		int to = lst[now][i].F;
		if(to == par)continue;
		dfs2(to, now);
		maxred[now] += maxred[to];
		pfred[now] += pfred[to];
	}
}

void dfs3(int now, int par, ll reduce){
	reduce += red[now];
	assert(reduce <= maxred[now]);
	int tp = -1;
	FOR(i,lst[now].size()){
		int to = lst[now][i].F;
		if(to == par){
			tp = i;
			continue;
		}
		ll nreduce = min(maxred[to]-pfred[to], reduce);
		dfs3(to, now, nreduce);
		reduce -= nreduce;
	}
	if(reduce > 0){
		w[lst[now][tp].S] -= reduce;
		p[lst[now][tp].S] -= reduce;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n;
    if(n == 1){
    	cout << 1 << endl;
    	return 0;
	}
    REP(i,2,n){
    	cin>>a[i]>>b[i]>>w[i]>>p[i];
    	lst[a[i]].pb(mp(b[i], i));
    	lst[b[i]].pb(mp(a[i], i));
	}
	
	dfs(1, -1);
	
	bool fail = false;
	REP(i,1,n){
		if(maxred[i] < 0)fail = true;
	}
	if(fail){
		cout << -1 << endl;
		return 0;
	}
	
	//REP(i,1,n)printf("%d: curw %lld minw %lld maxred %lld red %lld\n",i,curw[i],minw[i],maxred[i],red[i]);
    
    dfs2(1, -1);
    dfs3(1, -1, 0);
    
    cout << n << endl;
    REP(i,2,n)cout << a[i] << " " << b[i] << " " << w[i] << " " << p[i] << endl;
    
    return 0;
}

/*
5
1 2 2 3
2 4 2 9
4 5 5 6
4 3 4 8
*/