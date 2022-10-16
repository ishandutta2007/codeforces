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

const int N = 1e5 + 5;

int n,m,d;
vi lst[N];
string str[N];
int disc[N]; // precompute to -1
int low[N];
int scc[N]; // stores the id of scc of node i
stack<int>stk;
bool stkmember[N];
vi member[N];

int id, sccid; // set to 0
void tarjan(int now){
    if(disc[now] != -1)return;
    disc[now] = low[now] = ++id;
    stk.push(now);
    stkmember[now] = true;

    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(disc[to] == -1){
            tarjan(to);
            low[now] = min(low[now], low[to]);
        }else if(stkmember[to]){
            low[now] = min(low[now], disc[to]);
        }
    }

    //if root
    if(disc[now] == low[now]){
        sccid++;
        while(stk.top() != now){
            scc[stk.top()] = sccid;
            member[sccid].pb(stk.top());
            stkmember[stk.top()] = false;
            stk.pop();
        }
        scc[now] = sccid;
        member[sccid].pb(now);
        stkmember[now] = false;
        stk.pop();
    }
}

vi scclst[N];
int indeg[N];

const int M = 55;
int val[N*M];
bool vis[N][M];

int p[N*M];
int toid(int now, int day){
    return now * d + day;
}
int cek(int x){
    if(p[p[x]] != p[x])p[x] = cek(p[x]);
    return p[x];
}
void connect(int a, int b){
    if(cek(a) != cek(b)){
        p[cek(b)] = cek(a);
    }
}

int sz[N*M];
void bfs(int now, int day){
    if(vis[now][day])return;
//    printf(">>> bfs %d %d\n",now,day);
    int idd = toid(now, day);
    queue<pii>q;
    set<int>st;
    q.push(mp(now, day));
    vis[now][day] = true;
    while(!q.empty()){
        now = q.front().F;
        day = q.front().S;
        q.pop();
        
//        printf("now %d %d\n",now,day);
        if(str[now][day] == '1')st.insert(now);
        
        FOR(i,lst[now].size()){
            int to = lst[now][i];
            if(scc[now] != scc[to])continue;
            int nday = day+1;
            if(nday == d)nday = 0;
            if(vis[to][nday])continue;
            vis[to][nday] = true;
            connect(toid(now, day), toid(to, nday));
            q.push(mp(to, nday));
        }
    }
    sz[cek(idd)] = val[cek(idd)] = st.size();
}

vector<pair<pii, int> >qq[N]; // node, day, value
queue<int>khan;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>m>>d;
    REP(i,1,m){
        int a,b;
        cin>>a>>b;
        lst[a].pb(b);
    }
    REP(i,1,n)cin>>str[i];
    
    memset(disc, -1, sizeof disc);
    id = sccid = 0;
    REP(i,1,n){
        if(disc[i] == -1)tarjan(i);
    }
    REP(i,1,n){
        FOR(j,lst[i].size()){
            int to = lst[i][j];
            if(scc[i] != scc[to]){
                scclst[scc[i]].pb(scc[to]);
                indeg[scc[to]]++;
            }
        }
    }
    
    FOR(i,N*M){
        p[i] = i;
        val[i] = -OO;
    }
    qq[scc[1]].pb(mp(mp(1, 0), 0));
    REP(i,1,sccid){
        if(indeg[i] == 0)khan.push(i);
    }
    int ans = 0;
    while(!khan.empty()){
        int sccnow = khan.front();
        khan.pop();
        
//        printf("now at scc %d\n",sccnow);
        
        FOR(i,qq[sccnow].size()){
            int now = qq[sccnow][i].F.F;
            int day = qq[sccnow][i].F.S;
            int v = qq[sccnow][i].S;
//            printf("qq %d %d %d\n",now,day,v);
            
            bfs(now, day);
            int par = cek(toid(now, day));
            val[par] = max(val[par], sz[par] + v);
            ans = max(ans, val[par]);
        }
        
        FOR(i,scclst[sccnow].size()){
            int to = scclst[sccnow][i];
            indeg[to]--;
            if(indeg[to] == 0)khan.push(to);
        }
        FOR(i,member[sccnow].size()){
            int mm = member[sccnow][i];
            FOR(j,lst[mm].size()){
                int to = lst[mm][j];
                if(scc[mm] == scc[to])continue;
                FOR(k,d){
                    if(!vis[mm][k])continue;
                    int v = val[cek(toid(mm, k))];
                    qq[scc[to]].pb(mp(mp(to, (k+1)%d), v));
                }
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}

/*
6 7 3
3 1
1 2
2 4
4 1
2 3
5 3
1 6
011
110
111
001
111
111
*/