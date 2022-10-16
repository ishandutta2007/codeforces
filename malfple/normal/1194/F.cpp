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

const ll MOD = 1e9 + 7;
inline ll addmod(ll a, ll b){
    if(a+b<MOD)return a+b;
    return a+b-MOD;
}
inline ll submod(ll a, ll b){
    return addmod(a, MOD-b);
}
inline ll mulmod(ll a, ll b){
    return (a*b)%MOD;
}
inline ll expmod(ll a, ll e){
    ll ret = 1;
    while(e){
        if(e&1)ret = mulmod(ret, a);
        a = mulmod(a, a);
        e >>= 1;
    }
    return ret;
}
inline ll divmod(ll a, ll b){
    return mulmod(a, expmod(b, MOD-2));
}

const int N = 2e5 + 5;

int fac[N];
int C(int n, int r){
    return divmod(fac[n], mulmod(fac[r], fac[n-r]));
}

int n;
ll T;
int arr[N];
int use[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    fac[0] = 1;
    REP(i,1,N-5)fac[i] = mulmod(fac[i-1], i);
    
    cin>>n>>T;
    REP(i,1,n)cin>>arr[i];
    
    ll sum = 0;
    int r = 0, ccomb = 1;
    REP(i,1,n){
        sum += arr[i];
        if(sum > T)break;
        // raise
        ccomb = submod(mulmod(ccomb, 2), C(i-1, r));
        r++;
        ccomb = addmod(ccomb, C(i, r));
        while(r > T-sum){
            ccomb = submod(ccomb, C(i, r));
            r--;
        }
//        printf("%d -> curr comb, r = %d, ccomb = %d\n",i,r,ccomb);
        use[i] = mulmod(expmod(2, n-i), ccomb);
//        printf("use %d = %d\n",i, use[i]);
    }
    
    int ans = 0;
    REV(i,n,1){
        int cuse = submod(use[i], use[i+1]);
        ans = addmod(ans, mulmod(i, cuse));
    }
    ans = divmod(ans, expmod(2, n));
    cout << ans << endl;
    
    return 0;
}