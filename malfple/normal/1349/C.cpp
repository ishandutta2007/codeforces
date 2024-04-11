//pragma
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

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

const int N = 1005;
const int cx[] = {1,0,-1,0};
const int cy[] = {0,1,0,-1};

int n,m,t;
char col[N][N];

int delay[N][N];

queue<pii>q;
void init_ff(int x, int y){
    q.push({x, y});
    delay[x][y] = 0;
    while(!q.empty()){
        x = q.front().F;
        y = q.front().S;
        q.pop();

        FOR(k,4){
            int tx = x + cx[k];
            int ty = y + cy[k];
            if(tx < 1 || tx > n || ty < 1 || ty > m)continue;
            if(col[tx][ty] != col[x][y])continue;
            if(delay[tx][ty] != -1)continue;
            delay[tx][ty] = 0;
            q.push({tx, ty});
        }
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

    cin>>n>>m>>t;
    REP(i,1,n){
        REP(j,1,m){
            cin>>col[i][j];
        }
    }
    memset(delay, -1, sizeof delay);
    REP(i,1,n){
        REP(j,1,m){
            if(delay[i][j] != -1)continue;

            bool adj = false;
            FOR(k,4){
                int ti = i + cx[k];
                int tj = j + cy[k];
                if(ti < 1 || ti > n || tj < 1 || tj > m)continue;
                if(col[ti][tj] == col[i][j]){
                    adj = true;
                }
            }
            if(adj){
                init_ff(i, j);
            }
        }
    }


    // REP(i,1,n){
    //     REP(j,1,m){
    //         printf("%d ",delay[i][j]);
    //     }
    //     printf("\n");
    // }

    REP(i,1,n){
        REP(j,1,m){
            if(delay[i][j] == 0){
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        FOR(k,4){
            int tx = x + cx[k];
            int ty = y + cy[k];
            if(tx < 1 || tx > n || ty < 1 || ty > m)continue;
            if(delay[tx][ty] != -1)continue;
            delay[tx][ty] = delay[x][y] + 1;
            q.push({tx, ty});
        }
    }

    // REP(i,1,n){
    //     REP(j,1,m){
    //         printf("%d ",delay[i][j]);
    //     }
    //     printf("\n");
    // }

    REP(tc,1,t){
        int i,j;
        ll p;
        cin>>i>>j>>p;
        if(delay[i][j] == -1 || p <= delay[i][j]){
            cout << col[i][j] << endl;
        }else{
            int par = p - delay[i][j];
            if(par&1){
                cout << ((col[i][j] - '0') ^ 1) << endl;
            }else{
                cout << col[i][j] << endl;
            }
        }
    }

    return 0;
}