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

const int N = 1e6 + 5;

int sieve[N];

int n;
int arr[N];

vector<ll> primes;
void factorize(ll s){
    for(int i=2; (ll)i * i <= s; i++){
        if(sieve[i] != i)continue;
        if(s % i == 0){
            primes.pb(i);
            while(s % i == 0)s /= i;
        }
    }
    if(s > 1)primes.pb(s);
}

ll solve(ll p){ // all contents have to be multiple of p
    ll ret = 0;
    ll curr = 0;
    REP(i,1,n){
        curr = (curr + arr[i]) % p;
        ret += min(curr, p-curr);
    }
    // printf("solve %lld = %lld\n",p,ret);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    sieve[1] = 1;
    REP(i,2,N-1){
        if(sieve[i] == 0){
            REPP(j,i,N-1,i)sieve[j] = i;
        }
    }

    cin>>n;
    ll sum = 0;
    REP(i,1,n){
        cin>>arr[i];
        sum += arr[i];
    }

    if(sum == 1){
        cout << -1 << endl;
    }else{
        factorize(sum);

        ll ans = INF;
        FOR(i,primes.size()){
            ans = min(ans, solve(primes[i]));
        }
        cout << ans << endl;
    }

    return 0;
}