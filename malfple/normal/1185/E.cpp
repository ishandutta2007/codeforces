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

#define x1 laksdfj
#define x2 skljdflkjsdf
#define y1 sfjkldfjkl
#define y2 sdfkjkl

const int N = 2005;
const int A = 26;

int t;
int n,m;
char grid[N][N];
int x1[A], x2[A], y1[A], y2[A];

char grid2[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>t;
    while(t--){
        FOR(i,A){
            x1[i] = y1[i] = OO;
            x2[i] = y2[i] = -OO;
        }

        cin>>n>>m;
        int maxchar = -1;
        REP(i,1,n){
            REP(j,1,m){
                cin>>grid[i][j];
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                    int c = grid[i][j]-'a';
                    maxchar = max(maxchar, c);
                    x1[c] = min(x1[c], i);
                    x2[c] = max(x2[c], i);
                    y1[c] = min(y1[c], j);
                    y2[c] = max(y2[c], j);
                }
            }
        }

        bool fail = false;
        FOR(i,A){
            if(x1[i] == OO)continue;
            if(x2[i]-x1[i] > 0 && y2[i]-y1[i] > 0){
                fail = true;
            }
        }

        if(!fail){
            FORD(i,maxchar){
                if(x1[i] == OO){
                    x1[i] = x1[i+1];
                    x2[i] = x2[i+1];
                    y1[i] = y1[i+1];
                    y2[i] = y2[i+1];
                }
            }

            REP(i,1,n){
                REP(j,1,m){
                    grid2[i][j] = '.';
                }
            }

            FOR(k,maxchar+1){
                REP(i,x1[k],x2[k]){
                    REP(j,y1[k],y2[k]){
                        grid2[i][j] = k+'a';
                    }
                }
            }

            REP(i,1,n){
                REP(j,1,m){
                    if(grid[i][j] != grid2[i][j]){
                        fail = true;
                    }
                }
            }
        }

        if(fail)cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << maxchar+1 << endl;
            FOR(i,maxchar+1){
                cout << x1[i] << " " << y1[i] << " " << x2[i] << " " << y2[i] << endl;
            }
        }
    }

    return 0;
}