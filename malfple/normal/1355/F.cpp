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

const int N = 100005;
int sieve[N];
vi primes;

vi iprimes;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // #define endl '\n'
    // cout.setf(ios::fixed);
    // cout.setf(ios::showpoint);
    // cout.precision(10);

    sieve[1] = 1;
    REP(i,2,N-1){
        if(sieve[i] == 0){
            primes.pb(i);
            REPP(j,i,N-1,i){
                sieve[j] = i;
            }
        }
    }
    // cout << primes.size() << endl;
    // FOR(i,22)cout << primes[i] << endl;
    // REP(i,22,27)cout << "ddd " << primes[i] << endl;

    int t;
    cin>>t;
    while(t--){
        ll x = 1;
        int cp = 0;

        iprimes.clear();
        int cip = 0;

        FOR(i,22){
            ll worse = x;
            ll wcnt = 1;
            int cpp = cp;
            while(worse * primes[cpp] <= 1e9){
                worse *= primes[cpp++];
                wcnt *= 2;
            }
            // printf("worse %d\n",wcnt);

            if(wcnt <= 4){ // identify current primes;
                ll ask = 1;
                FOR(j,2){
                    if(cip < iprimes.size()){
                        ll cask = 1;
                        int p = iprimes[cip++];
                        // printf("ask prime %d\n",p);

                        while(cask * p <= 1e9){
                            cask *= p;
                        }

                        ask *= cask;
                    }
                }

                cout << "? " << ask << endl;
                ll res;
                cin>>res;

                FOR(j,iprimes.size()){
                    int p = iprimes[j];
                    int cnt = 0;
                    while(res % p == 0){
                        res /= p;
                        cnt++;
                    }
                    if(cnt > 1){
                        while(x % p == 0){
                            x /= p;
                        }
                        FOR(k,cnt){
                            x *= p;
                        }
                    }
                }
            }else{ // find new primes
                ll ask = 1;
                vi askp;
                while(ask <= INF / primes[cp]){
                    // printf("ask %d\n",primes[cp]);
                    ask *= primes[cp];
                    askp.pb(primes[cp++]);
                }

                cout << "? " << ask << endl;
                ll res;
                cin>>res;

                FOR(j,askp.size()){
                    if(res % askp[j] == 0){
                        x *= askp[j];
                        iprimes.pb(askp[j]);
                    }
                }
            }
        }

        ll divisors = 1;
        FOR(j, iprimes.size()){
            int p = iprimes[j];
            int cnt = 0;
            while(x % p == 0){
                x /= p;
                cnt++;
            }
            divisors *= (cnt+1);
        }
        cout << "! " << max(divisors + 7, divisors*2) << endl;
    }

    return 0;
}