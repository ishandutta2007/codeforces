#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

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

const ll MOD = 1e9 + 7;
inline ll addmod(ll a, ll b){
	return (a+b)%MOD;
}
inline ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}

const int N = 1e5 + 5;

vi primes;
void prec_primes(){
	primes.pb(2);
	REP(i,3,70){
		int cnt = 0;
		REP(j,2,i-1){
			if(i%j == 0)cnt++;
		}
		if(cnt == 0)primes.pb(i);
	}
}

int pow2[N];
void prec_pow2(){
	pow2[0] = 1;
	REP(i,1,N-5){
		pow2[i] = mulmod(pow2[i-1], 2);
	}
}

int n;
int cnt[75];
int nmask[75];
void prec_nmask(){
	nmask[1] = 0;
	REP(x,2,70){
		nmask[x] = 0;
		for(int i=0, tnow=x, mm=1; i<primes.size(); i++, mm<<=1){
			int cc = 0;
			while(tnow % primes[i] == 0){
				tnow /= primes[i];
				cc++;
			}
			if(cc&1)nmask[x] |= mm;
		}
	}
}

int memo[71][1<<19];
int dp(int now, int mask){
	if(now > 70){
		return mask == 0;
	}
	if(now == 1){
		return mulmod(pow2[cnt[1]], dp(now+1, mask));
	}
	if(cnt[now] == 0)return dp(now+1, mask);
	
	int& ret = memo[now][mask];
	if(ret != -1)return ret;
	
	ret = mulmod(pow2[cnt[now]-1], dp(now+1, mask));
	ret = addmod(ret, mulmod(pow2[cnt[now]-1], dp(now+1, mask ^ nmask[now])));
	return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    prec_primes();
    prec_pow2();
    prec_nmask();
    
    cin>>n;
    REP(i,1,n){
    	int x;
    	cin>>x;
    	cnt[x]++;
	}
	
	memset(memo, -1, sizeof memo);
	cout << (MOD+dp(1, 0)-1)%MOD << endl;
	
    return 0;
}