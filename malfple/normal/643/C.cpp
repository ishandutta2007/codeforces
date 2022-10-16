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
const int K = 55;

int n,k;
int arr[N];

ll sum[N];
double denom[N];
double pref[N];
double query(int l, int r){
    return pref[r] - pref[l-1] - (denom[r] - denom[l-1]) * (sum[l-1]);
}

double dp[K][N];

void dpdnc(int level, int l, int r, int bl, int br){
    if(l > r)return;

    double best;
    bool first = true;
    int bm = -1;
    int m = (l+r)/2;
    REP(i,bl, min(m,br)){
        double tmp = dp[level-1][i-1] + query(i,m);
        if(first){
            first = false;
            best = tmp;
            bm = i;
        }else if(tmp < best){
            best = tmp;
            bm = i;
        }
    }
    dp[level][m] = best;
    dpdnc(level, l, m-1, bl, bm);
    dpdnc(level, m+1, r, bm, br);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    n = getnum<int>();
    k = getnum<int>();
    REP(i,1,n)arr[i] = getnum<int>();

    REP(i,1,n){
        sum[i] = sum[i-1] + arr[i];
        denom[i] = denom[i-1] + 1.0L/arr[i];
        pref[i] = pref[i-1] + (double)sum[i]/arr[i];
    }

    REP(i,1,n)dp[1][i] = query(1, i);
    REP(i,2,k)dpdnc(i, 1,n, 1,n);

    cout << fixed << setprecision(12) << dp[k][n] << endl;

    return 0;
}