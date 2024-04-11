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
#define FORD(i,a) for(int i=a-1; i>=0; i--)

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

//end of macro

const int N = 200005;
const int M = 1000005;

// modular operations
const ll MOD = 1e9 + 7;
inline ll addmod(ll a, ll b){
	return (a+b)%MOD;
}
inline ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}

// power of 2
ll pow2[N];
inline void prec_pow2(){
	pow2[0] = 1;
	REP(i,1,N-5)pow2[i] = mulmod(pow2[i-1], 2);
}

//the dp
int dp[M];
inline void prec_dp(){
	REP(i,2,M-5){
		dp[i] += i;
		REPP(j,2*i,M-5,i){
			dp[j] -= dp[i];
		}
	}
}

int n;
int cnt[M];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    
    prec_pow2();
    prec_dp();
    
    cin>>n;
    REP(i,1,n){
    	int x;
    	cin>>x;
    	cnt[x]++;
    	for(int j=2; j*j <= x; j++){
    		if(x%j == 0){
	    		cnt[j]++;
	    		if(j*j != x)cnt[x/j]++;
    		}
		}
	}
	
	ll ans = 0;
	REP(i,1,M-5){
		if(cnt[i]>0){
			ans = addmod(ans, mulmod(mulmod(dp[i], cnt[i]), pow2[cnt[i]-1]));
		}
	}
	cout << ans << endl;

    return 0;
}