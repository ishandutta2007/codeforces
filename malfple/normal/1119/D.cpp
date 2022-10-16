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

const int N = 1e5 + 5;

int n,q;
ll arr[N];
vector<pair<ll,int> >lim;
ll pf[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n;
    REP(i,1,n)cin>>arr[i];
    sort(arr+1, arr+n+1);
    REP(i,1,n-1){
        lim.pb(mp(arr[i+1]-arr[i], i));
    }
    sort(lim.begin(), lim.end());
    FOR(i,lim.size()){
        pf[i+1] = pf[i];
        pf[i+1] += lim[i].F;
    }
    
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        a = b-a;
        if(n == 1){
            cout << a+1 << endl;
        }else{
            int lo = 0, hi = lim.size()-1, ans = -1;
            while(lo <= hi){
                int mid = (lo+hi)/2;
                if(lim[mid].F > a){
                    hi = mid-1;
                    ans = mid;
                }else{
                    lo = mid+1;
                }
            }
            
            ll vout = 0;
            if(ans == -1){
                vout = pf[lim.size()] + a + 1;
            }else{
                vout = pf[ans];
                vout += (n-ans) * (a + 1);
            }
            cout << vout << endl;
        }
    }
    
    return 0;
}