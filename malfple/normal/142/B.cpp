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

const int N = 1000005; // nodes numbered 1..N-2
const int SRC = 0; // source
const int SINK = N-1; // sink

struct edge{int to, flow, cap;};
vector<edge>edges; // edge list
vi lse[N]; // adjlist but with edge

void addEdge(int a, int b, int cap){
    lse[a].pb(edges.size());
    edges.pb({b, 0, cap});
    lse[b].pb(edges.size());
    edges.pb({a, 0, 0}); // here cap=0 cuz 1 way
}

int level[N]; // level graph
int lastEdge[N]; // to keep used paths from being flowed again

bool bfs(){ // create level graph, also returns false if no more flow is possible
    queue<int>q;
    memset(level, -1, sizeof level);

    q.push(SRC);
    level[SRC] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();

        FOR(i,lse[now].size()){
            edge& e = edges[lse[now][i]];
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
    for(int& i = lastEdge[now]; i<lse[now].size(); i++){
        edge& e = edges[lse[now][i]];
        if(e.flow == e.cap)continue; // no flow
        if(level[e.to] == level[now]+1){
            int curr = dfs(e.to, min(flow, e.cap - e.flow));
            if(curr > 0){
                e.flow += curr; // forward flow
                edges[lse[now][i]^1].flow -= curr; // residual
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
        printf("ret %d\n",ret); 
    }
    return ret;
}

const int cx[] = {-1,-2,-2,-1,1,2,2,1};
const int cy[] = {-2,-1,1,2,2,1,-1,-2};
const int D = 8;

int n,m;
inline int toid(int x, int y){
	return (x-1)*m + y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>n>>m;
    if(min(n,m) == 1)cout << max(n,m) << endl;
    else if(min(n,m) == 2)cout << 2 * (2 * (max(n,m)/4) + min(max(n,m)%4, 2)) << endl;
    else cout << n*m/2 + (n*m)%2 << endl;
    return 0;
    REP(i,1,n){
    	REP(j,1,m){
    		if((i+j)&1){
    			FOR(k,D){
    				int ti = i + cx[k];
    				int tj = j + cy[k];
    				if(ti >= 1 && ti <= n && tj >= 1 && tj <= m){
    					addEdge(toid(i,j), toid(ti, tj), 1);
					}
				}
				addEdge(SRC, toid(i,j), 1);
			}else{
				addEdge(toid(i,j), SINK, 1);
			}
		}
	}
	
	cout << n*m-maxFlow() << endl;

    return 0;
}