#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

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
#define ff first
#define ss second

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

const int SQRN = 4e5;

bool sieve[SQRN+1];
vi primes;
int prec_sieve(){
    REP(i,2,sqrt(SQRN)){
        if(sieve[i])continue;
        REPP(j,i*i,SQRN,i){
            sieve[j] = true;
        }
    }
    REP(i,2,SQRN){
        if(!sieve[i])primes.pb(i);
    }
}

int n;
int masks[SQRN+1];
set<int>leftover;

map<int,int>memo;
int dp(int mask){
    if(memo.find(mask) != memo.end())return memo[mask];

    int div = 1;
    int cetakan = 0;
    int tmask = mask>>1;
    set<int>st;
    while(div <= mask){
        st.insert(dp((mask&cetakan) | tmask));

        div<<=1;
        tmask>>=1;
        cetakan = cetakan<<1|1;
    }

    int ret = 0;
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        if(*it > ret)break;
        ret++;
    }
    return memo[mask] = ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prec_sieve();

    cin>>n;
    REP(i,1,n){
        int x;
        cin>>x;
        FOR(j,primes.size()){
            int cnt = 0;
            while(x%primes[j] == 0){
                x /= primes[j];
                cnt++;
            }
            if(cnt > 0){
                masks[primes[j]] |= (1<<(cnt-1));
            }
        }
        if(x > 1){
            leftover.insert(x);
        }
    }

    int ans = 0;
    FOR(i,primes.size()){
        ans ^= dp(masks[primes[i]]);
    }
    ans ^= (leftover.size()&1);

    if(ans)cout << "Mojtaba" << endl;
    else cout << "Arpa" << endl;

    return 0;
}