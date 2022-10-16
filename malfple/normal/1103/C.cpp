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

const int N = 2.5 * 1e5 + 5;
const int B = 18;

int n,m,k;
vi lst[N];

bool vis[N];
vi tlst[N];
vi bk[N];
int sparset[B+1][N];
int depth[N];
void dfs(int now, int par){
    vis[now] = true;
    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;
        if(vis[to]){
            bk[now].pb(to);
        }else{
            tlst[now].pb(to);
            sparset[0][to] = now;
            depth[to] = depth[now]+1;
            dfs(to, now);
        }
    }
}

int lca(int a, int b){
    if(depth[a] > depth[b])swap(a,b);
    REV(i,B,0){
        if(sparset[i][b] != -1 && depth[sparset[i][b]] >= depth[a]){
            b = sparset[i][b];
        }
    }
    if(a == b)return a;
    REV(i,B,0){
        if(sparset[i][a] != sparset[i][b]){
            a = sparset[i][a];
            b = sparset[i][b];
        }
    }
    return sparset[0][a];
}

int dist(int a, int b){
    int c = lca(a,b);
    return depth[a] + depth[b] - 2*depth[c];
}

void printpath(int a, int b){
    int c = lca(a,b);
    while(1){
        cout << a << " ";
        if(a == c)break;
        a = sparset[0][a];
    }
    stack<int>stk;
    while(b != c){
        stk.push(b);
        b = sparset[0][b];
    }
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n>>m>>k;
    REP(i,1,m){
        int a,b;
        cin>>a>>b;
        lst[a].pb(b);
        lst[b].pb(a);
    }
    
    sparset[0][1] = -1;
    depth[1] = 1;
    dfs(1, -1);
    
    REP(i,0,B-1){
        REP(j,1,n){
            if(sparset[i][j] == -1)sparset[i+1][j] = -1;
            else sparset[i+1][j] = sparset[i][sparset[i][j]];
        }
    }
    
    int deepest = 1;
    REP(i,2,n){
        if(depth[i] > depth[deepest])deepest = i;
    }
    
    if((ll)depth[deepest] * k >= n){
        cout << "PATH" << endl;
        cout << depth[deepest] << endl;
        while(1){
            cout << deepest << " ";
            if(deepest == 1)break;
            deepest = sparset[0][deepest];
        }
    }else{
        vi vec;
        REP(i,1,n){
            if(vec.size() == k)break;
            if(tlst[i].size() == 0)vec.pb(i);
        }
        
        cout << "CYCLES" << endl;
        FOR(i,vec.size()){
            int j = vec[i];
            int d1 = dist(j, bk[j][0])+1;
            int d2 = dist(j, bk[j][1])+1;
            if(d1 % 3){ // j -- 1st back
                cout << d1 << endl;
                printpath(j, bk[j][0]);
            }else if(d2 % 3){ // j -- 2nd back
                cout << d2 << endl;
                printpath(j, bk[j][1]);
            }else{ // 1st -- 2nd back
                cout << dist(bk[j][0], bk[j][1])+2 << endl;
                cout << j << " ";
                printpath(bk[j][0], bk[j][1]);
            }
        }
    }
    
    return 0;
}