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

const int N = 55;
const ll MOD = 1e9 + 7;

inline ll addmod(ll a, ll b){
	return (a+b)%MOD;
}
inline ll submod(ll a, ll b){
	return (MOD+a-b)%MOD;
}
inline ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}

int pow2[N];

int n,p;
int arr[N];

int dp[N][N][N][N]; // [id][0 par 0][0 par 1][1 par 0]

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    pow2[0] = 1;
    REP(i,1,N-1)pow2[i] = mulmod(pow2[i-1], 2);
    
    cin>>n>>p;
    REP(i,1,n)cin>>arr[i];
    
    int ans = 0;
    dp[0][0][0][0] = 1;
    REP(i,1,n){
    	REP(c0p0,0,i-1){
    		REP(c0p1,0,i-1-c0p0){
    			REP(c1p0,0,i-1-c0p0-c0p1){
    				if(dp[i-1][c0p0][c0p1][c1p0] == 0) continue;
    				
					int c1p1 = i-1-c0p0-c0p1-c1p0;
					
					//printf("at %d %d %d %d %d\n",i,c0p0,c0p1,c1p0,c1p1);
					int ways = dp[i-1][c0p0][c0p1][c1p0];
					//printf("dp[%d][%d][%d][%d] (%d) = %d\n",i-1,c0p0,c0p1,c1p0,c1p1,ways);
					ways = mulmod(ways, pow2[c0p0]);
					ways = mulmod(ways, pow2[c1p0]);
    				if(arr[i] == 0 || arr[i] == -1){
    					int nways = mulmod(ways, pow2[c0p1]);
    					int ways0, ways1;
    					if(c1p1 > 0)
							ways0 = ways1 = mulmod(nways, pow2[c1p1-1]);
						else{
							ways1 = nways;
							ways0 = 0;
						}
    					dp[i][c0p0+1][c0p1][c1p0] = addmod(dp[i][c0p0+1][c0p1][c1p0], ways0);
    					dp[i][c0p0][c0p1+1][c1p0] = addmod(dp[i][c0p0][c0p1+1][c1p0], ways1);
					}
					if(arr[i] == 1 || arr[i] == -1){
    					int nways = mulmod(ways, pow2[c1p1]);
    					int ways0, ways1;
    					//printf("curr %d\n",nways);
    					if(c0p1 > 0)
							ways0 = ways1 = mulmod(nways, pow2[c0p1-1]);
						else{
							ways1 = nways;
							ways0 = 0;
						}
    					dp[i][c0p0][c0p1][c1p0+1] = addmod(dp[i][c0p0][c0p1][c1p0+1], ways0);
    					dp[i][c0p0][c0p1][c1p0] = addmod(dp[i][c0p0][c0p1][c1p0], ways1);
					}
				}
			}
		}
	}
	
	REP(i,0,n){
		REP(j,0,n-i){
			REP(k,0,n-i-j){
				if((n-i-k)%2 != p)continue;
				//printf("dp[%d][%d][%d][%d] (%d) = %d\n",n,i,j,k,n-i-j-k,dp[n][i][j][k]);
				ans = addmod(ans, dp[n][i][j][k]);
			}
		}
	}
	cout << ans << endl;

    return 0;
}