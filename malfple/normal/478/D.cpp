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
	return (a+b)%MOD;
}

int r,g;

int used[1005];
int dp[2][(int)2e5+5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>r>>g;
    int h = 1;
    while((h+2)*(h+1)/2 <= r+g)h++;
    
    used[h] = h;
    REV(i,h-1,1)used[i] = used[i+1]+i;
    
    REP(j,0,r)dp[0][j] = 1; // base
    REP(i,1,h){
    	int idx = i&1; // 1=1, 2=0, 3=1, ...
    	REP(j,0,r)dp[idx][j] = 0;
    	
    	REP(j,0,r){
    		int k = r+g-used[i+1]-j;
    		if(k < 0 || k > g)continue; // i.e. invalid parameters
    		
    		if(j >= i)dp[idx][j] = addmod(dp[idx][j], dp[idx^1][j-i]);
    		if(k >= i)dp[idx][j] = addmod(dp[idx][j], dp[idx^1][j]);
		}
	}
	
	cout << dp[h&1][r] << endl;
    
    return 0;
}