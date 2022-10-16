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

int n;
ll a,r,m;
int arr[N];

ll cek(ll h){
    ll up = 0, down = 0;
    REP(i,1,n){
        if(arr[i] >= h)up += arr[i]-h;
        else down += h-arr[i];
    }

    ll move = min(up, down);
    return move * m + (up - move) * r + (down - move) * a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>a>>r>>m;
    REP(i,1,n)cin>>arr[i];

    // adjust costs
    m = min(m, a+r);

    ll lo = 0, hi = 1e9, ans = INF;
    while(hi-lo > 10){
        ll mid1 = (lo+lo+hi)/3;
        ll mid2 = (lo+hi+hi)/3;
        ll v1 = cek(mid1);
        ll v2 = cek(mid2);
        ans = min(ans, min(v1, v2));

        if(v1 < v2){
            hi = mid2;
        }else{
            lo = mid1;
        }
    }

    while(lo <= hi){
        ans = min(ans, cek(lo++));
    }

    cout << ans << endl;

    return 0;
}