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

inline int ask1(int i){
    cout << "? " << i << endl;
    int x;
    cin>>x;
    if(x == -1)exit(0);
    return x;
}
inline int ask2(int x){
    cout << "> " << x << endl;
    int r;
    cin>>r;
    if(r == -1)exit(0);
    return r;
}
inline void answer(int x, int d){
    cout << "! " << x << " " << d << endl;
}

int n;

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    #define endl '\n'
//    cout.setf(ios::fixed);
//    cout.setf(ios::showpoint);
//    cout.precision(10);
    
    cin>>n;
    int lo = 0, hi = 1e9, ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(ask2(mid) == 1){
            lo = mid+1;
        }else{
            ans = mid;
            hi = mid-1;
        }
    }
    int diff = -1;
    FOR(z,30){
        int c = irand(1,n);
        int x = ask1(c);
        if(x == ans)continue;
        if(diff == -1)diff = ans-x;
        else diff = __gcd(diff, ans-x);
    }
    
    answer(ans-(n-1)*diff, diff);
    
    return 0;
}