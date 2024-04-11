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

const int N = 2e5 + 5;

int sieve[N];
vi primes;
vi cnts[N];

int n;
int arr[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    sieve[1] = 1;
    REP(i,2,N-5){
        if(sieve[i] == 0){
            primes.pb(i);
            REPP(j,i,N-5,i){
                sieve[j] = i;
            }
        }
    }

    cin>>n;
    REP(i,1,n)cin>>arr[i];

    if(n <= 3){
        ll ans = -1;
        REP(i,1,n){
            REP(j,i+1,n){
                ll l = (ll)arr[i] * arr[j] / __gcd(arr[i], arr[j]);
                if(ans == -1)ans = l;
                else ans = __gcd(ans, l);
            }
        }

        cout << ans << endl;
        return 0;
    }

    REP(i,1,n){
        int x = arr[i];
        while(x > 1){
            int p = sieve[x];
            int cnt = 0;
            while(x % p == 0){
                cnt++;
                x /= p;
            }
            cnts[p].pb(cnt);
        }
    }

    ll ans = 1;
    FOR(i,N){
        // if(cnts[i].size()>0)printf("prime %d = %d\n",i,cnts[i].size());
        if(cnts[i].size() <= n-2)continue;
        while(cnts[i].size() < n)cnts[i].pb(0);
        sort(cnts[i].begin(), cnts[i].end());
        for(int j=0; j<cnts[i][1]; j++)ans *= i;
    }

    cout << ans << endl;

    return 0;
}