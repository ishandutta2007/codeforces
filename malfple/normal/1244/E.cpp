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
ll k;
ll a[N];
ll pf[N];
ll sf[N];

bool cek(ll lim){
//    printf("cek %d\n",lim);
    int j = 1;
    REP(i,1,n){
        while(j < n && a[j+1] - a[i] <= lim){
            j++;
        }
        
        ll tmp = 0;
        if(i > 1){
            tmp += (ll)a[i] * (i-1) - pf[i-1];
        }
        if(j < n){
            tmp += sf[j+1] - (ll)(a[i] + lim) * (n-j);
        }
        
        if(tmp <= k){
            return true;
        }
    }
    j = n;
    REV(i,n,1){
        while(j > 1 && a[i] - a[j-1] <= lim){
            j--;
        }
        
        ll tmp = 0;
        if(j > 1){
            tmp += (ll)(a[i] - lim) * (j-1) - pf[j-1];
        }
        if(i < n){
            tmp += sf[i+1] - (ll)a[i] * (n-i);
        }
        
        if(tmp <= k){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n>>k;
    REP(i,1,n)cin>>a[i];
    sort(a+1, a+n+1);
    
    REP(i,1,n)pf[i] = pf[i-1] + a[i];
    REV(i,n,1)sf[i] = sf[i+1] + a[i];
    
    ll lo = 0, hi = 1e9, ans = 1e9;
    while(lo <= hi){
        ll mid = (lo+hi)/2;
        if(cek(mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}