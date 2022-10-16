#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
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
#define FORD(i,a) for(int i=a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

const int N = 100005;
const int E = 16;

int n,m;
vi lst[N];

int depth[N];
int sparset[E+1][N];

void dfs(int idx,int par){
    sparset[0][idx] = par;

    FOR(i,lst[idx].size()){
        int to = lst[idx][i];
        if(to == par)continue;
        depth[to] = depth[idx]+1;
        dfs(to, idx);
    }
}

inline int LCA(int a,int b){
    if(depth[a] > depth[b]){
        REV(i,E,0){
            if(depth[sparset[i][a]] >= depth[b])a = sparset[i][a];
        }
    }else if(depth[a] < depth[b]){
        REV(i,E,0){
            if(depth[sparset[i][b]] >= depth[a])b = sparset[i][b];
        }
    }

    if(a == b)return a;

    REV(i,E,0){
        if(sparset[i][a] != sparset[i][b]){
            a = sparset[i][a];
            b = sparset[i][b];
        }
    }

    return sparset[0][a];
}

inline int getDist(int a,int b){
    int lca = LCA(a,b);

    return depth[a] + depth[b] - 2*depth[lca];
}

int dist[N];
vi reds;

inline void apply(){
    queue<pii>q;

    FOR(i,reds.size()){
        q.push(mp(reds[i], 0));
    }
    reds.clear();

    while(!q.empty()){
        int now = q.front().ff;
        int d = q.front().ss;
        q.pop();

        if(dist[now] <= d)continue;
        dist[now] = d;

        FOR(i,lst[now].size()){
        	if(dist[lst[now][i]] <= d+1)continue;
            q.push(mp(lst[now][i], d+1));
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie();

    scanf("%d %d",&n,&m);//cin>>n>>m;
    REP(i,1,n-1){
        int a,b;
        scanf("%d %d",&a,&b);//cin>>a>>b;

        lst[a].pb(b);
        lst[b].pb(a);
    }

    depth[1] = 1;
    dfs(1, -1);

    FOR(i,E){
        REP(j,1,n){
            if(sparset[i][j] == -1)sparset[i+1][j] = -1;
            else sparset[i+1][j] = sparset[i][sparset[i][j]];
        }
    }

    REP(i,1,n)dist[i] = depth[i]-1;

    int lim = sqrt(m);
    REP(z,1,m){
        int ord,x;
        scanf("%d %d",&ord,&x);//cin>>ord>>x;

        if(ord == 1){
            reds.pb(x);
        }else{
            int ans = dist[x];
            FOR(i,reds.size()){
                ans = min(ans, getDist(reds[i], x));
            }
            printf("%d\n",ans);//cout << ans << endl;
        }
        
        if(z % lim == 0)apply();
    }

    return 0;
}