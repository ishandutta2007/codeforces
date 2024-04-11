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

const int N = 1005;

int n,m;
int arr[N][N];

ll dptl[N][N];
ll dptr[N][N];
ll dpbl[N][N];
ll dpbr[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>n>>m;
    REP(i,1,n){
    	REP(j,1,m){
    		cin>>arr[i][j];
		}
	}
	
	REP(i,1,n){
		REP(j,1,m){
			dptl[i][j] = max(dptl[i-1][j], dptl[i][j-1]);
			dptl[i][j] += arr[i][j];
		}
		REV(j,m,1){
			dptr[i][j] = max(dptr[i-1][j], dptr[i][j+1]);
			dptr[i][j] += arr[i][j];
		}
	}
	REV(i,n,1){
		REP(j,1,m){
			dpbl[i][j] = max(dpbl[i+1][j], dpbl[i][j-1]);
			dpbl[i][j] += arr[i][j];
		}
		REV(j,m,1){
			dpbr[i][j] = max(dpbr[i+1][j], dpbr[i][j+1]);
			dpbr[i][j] += arr[i][j];
		}
	}
	
	ll ans = 0;
	REP(i,2,n-1){
		REP(j,2,m-1){
			ans = max(ans, dptl[i-1][j] + dptr[i][j+1] + dpbl[i][j-1] + dpbr[i+1][j]);
			ans = max(ans, dptl[i][j-1] + dptr[i-1][j] + dpbl[i+1][j] + dpbr[i][j+1]);
		}
	}
	cout << ans << endl;
    
    return 0;
}