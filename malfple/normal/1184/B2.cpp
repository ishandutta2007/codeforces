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

const int N = 2005;
const int SRC = N-2;
const int SINK = N-1;

struct edge{int to, flow, cap, rev;};
vector<edge> lst[N]; // adjlist

void addEdge(int a, int b, int cap){
    int sa = lst[a].size(), sb = lst[b].size();
    lst[a].pb({b, 0, cap, sb});
    lst[b].pb({a, 0, 0, sa}); // here cap=0 cuz 1 way
}

int level[N]; // level graph
int lastEdge[N]; // to keep used paths from being flowed again

bool bfs(){ // create level graph, returns false if no more flow is possible
    queue<int>q;
    memset(level, -1, sizeof level);

    q.push(SRC);
    level[SRC] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();

        FOR(i,lst[now].size()){
            edge& e = lst[now][i];
            if(level[e.to] != -1)continue;
            if(e.flow < e.cap){ // flow still possible
                level[e.to] = level[now]+1;
                q.push(e.to);
            }
        }
    }
    return level[SINK] != -1;
}

int dfs(int now, int flow){ // do the flow
    if(now == SINK)return flow;

    int ret = 0;
    for(int& i = lastEdge[now]; i<lst[now].size(); i++){
        edge& e = lst[now][i];
        if(e.flow == e.cap)continue; // no flow
        if(level[e.to] == level[now]+1){
            int curr = dfs(e.to, min(flow, e.cap - e.flow));
            if(curr > 0){
                e.flow += curr; // forward flow
                lst[e.to][e.rev].flow -= curr; // residual
                flow -= curr;
                ret += curr;
                if(flow == 0)return ret; // if flow to this node is already depleted, i.e. there is a bottleneck far before this node
            }
        }
    }
    return ret;
}

int maxFlow(){
    int ret = 0;
    while(bfs()){
        memset(lastEdge, 0, sizeof lastEdge);
        ret += dfs(SRC, OO);
    }
    return ret;
}

const int M = 1005;
int n,m;
int adj[105][105];
int s,b,k,h;
int xs[M], a[M], f[M];
int xb[M], d[M];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n>>m;
    REP(i,1,n)REP(j,1,n)adj[i][j] = OO;
    REP(i,1,n)adj[i][i] = 0;
    REP(i,1,m){
        int a,b;
        cin>>a>>b;
        adj[a][b] = adj[b][a] = 1;
    }
    REP(k,1,n){
        REP(i,1,n){
            REP(j,1,n){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    
    cin>>s>>b>>k>>h;
    REP(i,1,s){
        addEdge(SRC, i, 1);
        cin>>xs[i]>>a[i]>>f[i];
    }
    REP(i,1,b){
        addEdge(s+i, SINK, 1);
        cin>>xb[i]>>d[i];
    }
    
    REP(i,1,s){
        REP(j,1,b){
            if(a[i] < d[j])continue;
            if(f[i] < adj[xs[i]][xb[j]])continue;
            addEdge(i, s+j, 1);
        }
    }
    
    int mx = maxFlow();
//    printf("max match = %d\n",mx);
    int unmatched = s - mx;
    
    ll ans = (ll)mx * k;
    REP(i,1,s){ // put dummy
        if(unmatched)unmatched--;
        else mx--;
        ans = min(ans, (ll)mx * k + (ll)i * h);
    }
    cout << ans << endl;
    
    return 0;
}