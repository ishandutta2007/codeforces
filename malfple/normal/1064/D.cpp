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
const int cx[] = {0,1,0,-1};
const int cy[] = {1,0,-1,0};

int n,m;
int r,c;
int x,y;
char arr[N][N];

struct state{
    int x, y;
    int lx, ly;

    bool operator<(const state& other) const {
        return lx+ly < other.lx+other.ly;
    }
};

bool vis[N][N];
priority_queue<state>q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>m;
    cin>>r>>c;
    cin>>x>>y;

    REP(i,1,n){
        REP(j,1,m){
            cin>>arr[i][j];
        }
    }

    int ans = 0;
    q.push({r, c, x, y});
    while(!q.empty()){
        state now = q.top();
        q.pop();

        if(now.x < 1 || now.x > n || now.y < 1 || now.y > m)continue;
        if(now.lx < 0 || now.ly < 0)continue;
        if(arr[now.x][now.y] == '*')continue;
        if(vis[now.x][now.y])continue;
        vis[now.x][now.y] = true;
        ans++;

        // printf("%d %d -> %d %d\n",now.x,now.y,now.lx,now.ly);

        FOR(k,4){
            int nx = now.x + cx[k];
            int ny = now.y + cy[k];
            int nlx = now.lx;
            int nly = now.ly;
            if(cy[k] == -1)nlx--;
            else if(cy[k] == 1)nly--;
            q.push({nx, ny, nlx, nly});
        }
    }
    cout << ans << endl;

    return 0;
}