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
 
int n,m;
int arr[N];
int s;
 
vi lst[N];
int disc[N]; // precompute to -1
int low[N];
int scc[N]; // stores the id of scc of node i
stack<int>stk;
bool stkmember[N];
 
int id, sccid; // set to 0
bool isCycle[N];
void tarjan(int now, int par){
    if(disc[now] != -1)return;
    disc[now] = low[now] = ++id;
    stk.push(now);
    stkmember[now] = true;
 
    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        if(disc[to] == -1){
            tarjan(to, now);
            low[now] = min(low[now], low[to]);
        }else if(stkmember[to]){
            low[now] = min(low[now], disc[to]);
        }
    }
 
    //if root
    if(disc[now] == low[now]){
        sccid++;
        bool moreThanOne = false;
        while(stk.top() != now){
            scc[stk.top()] = sccid;
            stkmember[stk.top()] = false;
            isCycle[stk.top()] = true;
            stk.pop();
            moreThanOne = true;
        }
        scc[now] = sccid;
        stkmember[now] = false;
        stk.pop();
        if(moreThanOne) isCycle[now] = true;
    }
}
 
int p[N];
ll val[N];
int cek(int x){
    if(p[p[x]] != p[x])p[x] = cek(p[x]);
    return p[x];
}
inline void combine(int a, int b){
    if(cek(a) != cek(b)){
        val[cek(a)] += val[cek(b)];
        p[cek(b)] = cek(a);
    }
}
 
bool vis[N];
bool toCycle[N];
void dfs(int now, int par, bool pastCycle){
    if(isCycle[now]){
        pastCycle = true;
        toCycle[now] = true;
    }
 
    vis[now] = true;
    FOR(i, lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
 
        if(vis[to])continue;
        dfs(to, now, pastCycle);
        if(toCycle[to]){
            toCycle[now] = true;
        }
    }
 
    // printf("now %d %d, pastCycle %d, toCycle %d\n",now,par, pastCycle, toCycle[now]);
 
    // if(isCycle[now] || (pastCycle && toCycle[now])){
    //     if(par != -1)combine(now, par);
    // }
}
 
void dfs2(int now, int par, bool pastCycle){
    if(isCycle[now]){
        pastCycle = true;
        if(par != -1 && scc[now] == scc[par]){
            combine(now, par);
        }
    }
 
    vis[now] = true;
    int toCycleCnt = 0;
    FOR(i, lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        if(vis[to])continue;
        if(toCycle[to]){
            toCycleCnt++;
        }
    }
 
    // printf("now %d %d, pastCycle %d, toCycle %d\n",now,par, pastCycle, toCycle[now]);
 
    if(pastCycle && toCycle[now]){
        if(par != -1)combine(now, par);
        isCycle[now] = true;
    }
    if(!isCycle[now]){
        if(toCycleCnt > 1){
            pastCycle = true;
            isCycle[now] = true;
        }
    }
 
    FOR(i, lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        if(vis[to])continue;
        dfs2(to, now, pastCycle);
    }
}

void dfs3(int now, int par){
    if(par != -1)combine(now, par);
    if(isCycle[now])return;
    isCycle[now] = true;
    
    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        if(toCycle[to]) dfs3(to, now);
    }
}

ll dp(int now, int par){
    ll ret = 0;
 
    vis[now] = true;
    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        if(vis[to])continue;
 
        ret = max(ret, dp(to, now));
    }
 
    if(par == -1 || cek(now) != cek(par)){
        ret += val[cek(now)];
    }
 
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
 
    cin>>n>>m;
    REP(i,1,n)cin>>arr[i];
    REP(i,1,m){
        int a,b;
        cin>>a>>b;
        lst[a].pb(b);
        lst[b].pb(a);
    }
    cin>>s;
 
    memset(disc, -1, sizeof disc);
    id = sccid = 0;
    tarjan(s, -1);
 
    // REP(i,1,n){
    //     printf("%d ",isCycle[i]);
    // }printf("\n");
 
    REP(i,1,n){
        p[i] = i;
        val[i] = arr[i];
    }
    dfs(s, -1, false);
 
    memset(vis, 0, sizeof vis);
    dfs2(s, -1, false);
 
    // REP(i,1,n)printf("%d ",cek(i));
    // printf("\n");
    
    dfs3(s, -1);
 
    memset(vis, 0, sizeof vis);
    cout << dp(s, -1) << endl;
 
    return 0;
}
 
/*
13 14
1 1 1 1 1 1 1 1 1 1 1 1000 1001
1 2
1 3
2 3
3 4
4 5
5 6
6 7
7 8
8 9
7 9
5 10
10 11
11 12
11 13
1
 
13 14
1 1 1 1 1 1 1 1 1 1 1 1000 1001
1 2
1 3
2 3
3 4
4 5
5 6
6 7
7 8
8 9
7 9
5 10
10 11
11 12
11 13
13
 
14 15
1 1 1 1 1 1 1 1 1 1 1 1000 1001 100000
1 2
1 3
2 3
3 4
4 5
5 6
6 7
7 8
8 9
7 9
5 10
10 11
11 12
11 13
8 14
4
*/