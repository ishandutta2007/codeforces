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

const int N = 1e5 + 5;

int t;
int nr, ng, nb;

set<int>r,g,b;

inline ll getval(ll x, ll y, ll z){
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}

inline ll solve(set<int>& a, set<int>& b, set<int>& c){
    ll ret = 4 * INF;
    for(auto& x : a){
        auto ib = b.lower_bound(x);
        auto ic = c.lower_bound(x);

        if(ib != b.end() && ic != c.end()){
            ret = min(ret, getval(x, *ib, *ic));
        }
        auto tib = ib;
        if(ib != b.begin()){
            ib--;
            if(ic != c.end()) ret = min(ret, getval(x, *ib, *ic));
        }
        ib = tib;
        if(ic != c.begin()){
            ic--;
            if(ib != b.end())ret = min(ret, getval(x, *ib, *ic));
            if(ib != b.begin()){
                ib--;
                ret = min(ret, getval(x, *ib, *ic));
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>t;
    while(t--){
        r.clear(); g.clear(); b.clear();

        cin>>nr>>ng>>nb;
        REP(i,1,nr){
            int x; cin>>x;
            r.insert(x);
        }
        REP(i,1,ng){
            int x; cin>>x;
            g.insert(x);
        }
        REP(i,1,nb){
            int x; cin>>x;
            b.insert(x);
        }

        ll ans = 4 * INF;
        ans = min(ans, solve(r, g, b));
        ans = min(ans, solve(g, r, b));
        ans = min(ans, solve(b, r, g));
        cout << ans << endl;
    }

    return 0;
}