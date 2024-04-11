#include <iostream>
#include <vector>
#include <utility>

#include <cstdlib>
#include <cstring>

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

const ll MOD = 1e8;
inline ll addmod(ll a, ll b){return (a+b)%MOD;}
inline ll submod(ll a, ll b){return (MOD+a-b)%MOD;}

// end of MOD

const int N = 105;

int n1,n2,k1,k2;

int memo[N][N][2];
int dp(int l1, int l2, bool p1){
    if(l1 == 0){
        return l2 <= k2;
    }else if(l2 == 0){
        return l1 <= k1;
    }

    int& ret = memo[l1][l2][p1];
    if(ret != -1)return ret;
    ret = 0;

    if(p1){
        REP(i,1,min(l1, k1)){
            ret = addmod(ret, dp(l1-i, l2, 0));
        }
    }else{
        REP(i,1,min(l2, k2)){
            ret = addmod(ret, dp(l1, l2-i, 1));
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'

    cin>>n1>>n2>>k1>>k2;

    memset(memo, -1, sizeof memo);
    cout << addmod(dp(n1, n2, 0), dp(n1, n2, 1)) << endl;

    return 0;
}