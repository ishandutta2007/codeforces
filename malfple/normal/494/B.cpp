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

const int N = 1e5 + 5;

string str,pat;
int kmp[N];
int lval[N];

int dp[N];
int pf1[N];
int pf2[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>str>>pat;
    kmp[0] = -1;
	for(int i=0, j=-1; i < pat.size(); i++, j++){
	    while ((j >= 0) && (pat[i] != pat[j])) j = kmp[j];
	    kmp[i+1] = j+1;
	}
	
	FOR(i,str.size())lval[i] = -1;
	for(int i=0, j=0; i < str.size(); i++, j++){
	    while ((j >= 0) && (j >= pat.size() || str[i] != pat[j])) j = kmp[j];
	    if (j+1 == pat.size()){
	        //printf("found %d\n",i-j);
	        lval[i] = i-j;
	    }
	}
	REP(i,1,(int)str.size()-1)lval[i] = max(lval[i], lval[i-1]);
	
	int ans = 0;
	pf1[0] = 1;
	pf2[0] = 1;
	FOR(i,str.size()){
		if(lval[i] != -1){
			dp[i] = addmod(dp[i], pf2[lval[i]]);
		}
		pf1[i+1] = addmod(pf1[i], dp[i]);
		pf2[i+1] = addmod(pf2[i], pf1[i+1]);
		//printf("dp[%d] = %d\n",i,dp[i]);
		ans = addmod(ans, dp[i]);
	}
	cout << ans << endl;
    
    return 0;
}