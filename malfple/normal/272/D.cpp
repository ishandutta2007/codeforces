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

ll MOD;
inline ll addmod(ll a, ll b){
	return (a+b)%MOD;
}
inline ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}

struct superInteger{
	ll pow2, v;
	superInteger(){
		pow2 = v = 0;
	}
	superInteger(int x){
		pow2 = v = 0;
		while(!(x&1)){
			pow2++;
			x >>= 1;
		}
		v = x;
	}
	
	superInteger operator* (const superInteger& a){
		superInteger ret;
		ret.pow2 = pow2 + a.pow2;
		ret.v = mulmod(v, a.v);
		return ret;
	}
	superInteger operator* (int x){
		return (*this) * superInteger(x);
	}
	
	void print()const {
		printf("2^%d * %d\n",pow2,v);
	}
	void printI(){
		ll ret = v, e = pow2, mul = 2;
		while(e){
			if(e&1)ret = mulmod(ret, mul);
			mul = mulmod(mul, mul);
			e >>= 1;
		}
		cout << ret << endl;
	}
};

int n;
int a[N], b[N];
superInteger fac[N];

vii vec;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'

	cin>>n;
	REP(z,1,2){
		REP(i,1,n){
			int x;
			cin>>x;
			vec.pb(mp(x,i));
		}
	}
	cin>>MOD;
	
	fac[1] = 1;
	REP(i,2,N-5)fac[i] = fac[i-1] * i;
	
	sort(vec.begin(), vec.end());
	
	superInteger ans = 1;
	int cnt = 0;
	int same = 0;
	FOR(i,vec.size()){
		cnt++;
		if(i+1 < vec.size() && vec[i] == vec[i+1])same++;
		if(i+1 == vec.size() || vec[i].F != vec[i+1].F){
			ans = ans * fac[cnt];
			ans.pow2 -= same;
			cnt = same = 0;
		}
	}
	
	ans.printI();

    return 0;
}