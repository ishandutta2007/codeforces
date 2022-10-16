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

const int N = 1e5 + 5;

int n,k;
int a[N], d[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>k;
    REP(i,1,n)cin>>a[i];
    REP(i,1,n)cin>>d[i];

    ll en = max(0, a[n] - d[n]); // exciting only 
    ll ans = en;
    if(k == 0){
        ll curr = 0;
        REV(i,n,1){
            curr += a[i];
            ans = max(ans, curr - d[i]);
        }
    }else if(k >= 2){ // connect all
        ll curr = 0;
        REP(i,1,n)curr += a[i];
        int mn = OO;
        REP(i,1,n-1)mn = min(mn, d[i]);
        curr -= mn;

        ans = max(ans, curr);
    }else{ // k == 1
        // one huge cycle
        ll curr = 0;
        int mn = OO;
        REP(i,1,n-1)curr += a[i];
        REP(i,1,n-1)mn = min(mn, d[i]);
        ans = max(ans, curr - mn + en);

        // change first and get rid of it
        curr = 0;
        REV(i,n,2){
            curr += a[i];
            ans = max(ans, curr - d[i]);
        }

        // skip one
        curr = 0;
        mn = OO;
        REP(i,2,n)mn = min(mn, a[i] + max(0, a[i]-d[i]));
        REP(i,1,n)curr += a[i];
        ans = max(ans, curr - mn - d[1]);

        // exciting 2 and get all
        curr = 0;
        mn = OO;
        int mn2 = OO;
        REP(i,1,n){
            curr += a[i];
            mn = min(mn, d[i]);
            if(mn < mn2)swap(mn, mn2);
        }
        ans = max(ans, curr - mn - mn2);
    }
    cout << ans << endl;

    return 0;
}