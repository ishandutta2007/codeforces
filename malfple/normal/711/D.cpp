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
inline ll powmod(ll a, ll e){
    ll ret = 1;
    while(e){
        if(e&1)ret = mulmod(ret, a);
        a = mulmod(a, a);
        e >>= 1;
    }
    return ret;
}

const int N = 2e5 + 5;

int n;
int to[N];

int sz[N];
int p[N];
int cek(int x){
    if(p[p[x]] != p[x])p[x] = cek(p[x]);
    return p[x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n;
    REP(i,1,n){
        p[i] = i;
        sz[i] = 1;
    }
    REP(i,1,n){
        cin>>to[i];
        if(cek(i) != cek(to[i])){
            sz[cek(to[i])] += sz[cek(i)];
            p[cek(i)] = cek(to[i]);
        }
    }

    int ans = 1;
    REP(i,1,n){
        if(cek(i) == i){
            int loopl = 1;
            int now = to[i];
            while(now != i){
                now = to[now];
                loopl++;
            }
            ans = mulmod(ans, submod(powmod(2, sz[i]), mulmod(2, powmod(2, sz[i]-loopl))));
        }
    }
    cout << ans << endl;

    return 0;
}