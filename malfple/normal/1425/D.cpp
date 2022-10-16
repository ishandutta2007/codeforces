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

#define ALL(v) v.begin(), v.end()

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

const ll MOD = 1e9 + 7;

inline ll domod(ll x){
    if(abs(x) >= MOD) x %= MOD;
    if(x < 0)x += MOD;
    return x;
}
inline ll addmod(ll a, ll b){
    a += b; if(a >= MOD) a -= MOD; return a;
}
inline ll submod(ll a, ll b){
    a -= b; if(a < 0) a += MOD; return a;
}
inline ll mulmod(ll a, ll b){return (a*b)%MOD;}
inline ll powmod(ll a, ll e){
    ll ret = 1;
    while(e){
        if(e&1)ret = mulmod(ret, a);
        a = mulmod(a, a);
        e >>= 1;
    }
    return ret;
}
inline ll invmod(ll a){ // change this if non-prime modulus
    return powmod(a, MOD-2);
}
inline ll divmod(ll a, ll b){
    return mulmod(a, invmod(b));
}

const int N = 2e3 + 5;
const int M = 1000;

ll fac[N];
ll C(int n, int r){
    if(n < r)return 0;
    return divmod(fac[n], mulmod(fac[r], fac[n-r]));
}

int n,m,r;
int x[N], y[N], b[N];
int hit[N];

int pf[M+1][M+1];
inline void prec(){
    REP(i,1,M){
        REP(j,2,M){
            pf[i][j] += pf[i][j-1];
        }
    }
    REP(j,1,M){
        REP(i,2,M){
            pf[i][j] += pf[i-1][j];
        }
    }
}
inline int gett(int x1, int y1, int x2, int y2){
    x1 = max(x1, 1);
    x2 = min(x2, M);
    y1 = max(y1, 1);
    y2 = min(y2, M);
    if(x1 > x2)return 0;
    if(y1 > y2)return 0;
    // printf("get %d %d %d %d = %d\n",x1,y1,x2,y2,pf[x2][y2] - pf[x1-1][y2] - pf[x2][y1-1] + pf[x1-1][y1-1]);
    return pf[x2][y2] - pf[x1-1][y2] - pf[x2][y1-1] + pf[x1-1][y1-1];
}

ll f1[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    fac[0] = 1;
    REP(i,1,N-1)fac[i] = mulmod(fac[i-1], i);

    cin>>n>>m>>r;
    REP(i,1,n){
        cin>>x[i]>>y[i]>>b[i];
        pf[x[i]][y[i]] = 1;
    }
    prec();
    REP(i,1,n)hit[i] = gett(x[i]-r, y[i]-r, x[i]+r, y[i]+r);


    ll U = C(n, m);
    ll ans = 0;

    // printf("UNVIERAL %d\n",U);

    REP(i,1,n){
        // printf("hit %d = %d\n",i,hit[i]);
        f1[i] = submod(U, C(n-hit[i], m));
        // printf("ways %d = %d\n",i,f1[i]);
        ans = addmod(ans, mulmod(mulmod(b[i], b[i]), f1[i]));
        // printf("%d -> %d\n",i, mulmod(mulmod(b[i], b[i]), f1[i]));
    }

    REP(i,1,n){
        REP(j,i+1,n){
            int x1 = max(x[i]-r, x[j]-r);
            int y1 = max(y[i]-r, y[j]-r);
            int x2 = min(x[i]+r, x[j]+r);
            int y2 = min(y[i]+r, y[j]+r);
            int thit = hit[i] + hit[j] - gett(x1, y1, x2, y2);
            ll ex = submod(U, C(n-thit, m));
            ll f2 = submod(addmod(f1[i], f1[j]), ex);

            ans = addmod(ans, mulmod(2, mulmod(mulmod(b[i], b[j]), f2)));
            // printf("%d %d -> %d\n",i,j,mulmod(2, mulmod(mulmod(b[i], b[j]), f2)));
        }
    }

    cout << ans << endl;

    return 0;
}