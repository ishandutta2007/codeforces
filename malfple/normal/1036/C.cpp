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

string str;
ll memo[22][3][2];
ll dp(int idx, int used, bool bocor){
	if(idx == str.size())return 1;
	if(used == 3)return 1;
	
	ll& ret = memo[idx][used][bocor];
	if(ret != -1)return ret;
	
	// lewat
	if(str[idx] == '0')ret = dp(idx+1, used, bocor);
	else ret = dp(idx+1, used, true);
	
	// use
	REP(i,1,9){
		if(bocor)ret += dp(idx+1, used+1, true);
		else{
			if(i > str[idx]-'0')continue;
			if(i == str[idx]-'0')ret += dp(idx+1, used+1, false);
			else ret += dp(idx+1, used+1, true);
		}
	}
	
	return ret;
}

ll work(ll x){
	str = "";
	while(x){
		str += char(x%10 + '0');
		x/=10;
	}
	reverse(str.begin(), str.end());
	
	memset(memo, -1, sizeof memo);
	return dp(0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    int t;
    cin>>t;
    while(t--){
    	ll l,r;
    	cin>>l>>r;
    	cout << work(r) - work(l-1) << endl;
	}

    return 0;
}