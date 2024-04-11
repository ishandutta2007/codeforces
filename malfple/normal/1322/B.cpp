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

const int N = 4e5 + 5;

int n;
int arr[N];

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
    
    int ans = 0;
    REV(i,25,0){
    	int th = 1<<i;
    	sort(arr+1, arr+n+1);
    	
    	ll cnt = 0;
    	REP(j,1,n){
    		auto a = lower_bound(arr+j+1, arr+n+1, th - arr[j]);
    		auto b = upper_bound(arr+j+1, arr+n+1, 2*th-1 - arr[j]);
    		auto c = lower_bound(arr+j+1, arr+n+1, th*3 - arr[j]);
//    		printf("cek %d -> %d %d\n",arr[j],a-arr,b-arr);
			cnt += b-a;
			if(c != arr+n+1){
				cnt += arr+n+1 - c;
			}
		}
		
//		printf("bit %d = %d\n",i,cnt);
		if(cnt&1){
			ans |= th;
//			printf("bit %d on\n",i);
		}
		
		REP(j,1,n){
			if(arr[j] >= th){
				arr[j] -= th;
			}
		}
	}
	
	cout << ans << endl;
    
    return 0;
}