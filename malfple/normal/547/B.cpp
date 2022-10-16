#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
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
#define ff first
#define ss second

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

int n;
int arr[N];
vii sorter;
int ans[N];

int p[N];
int cnt[N];
int cek(int x){
	if(p[p[x]] != p[x])p[x] = cek(p[x]);
	return p[x];
}

inline void connect(int a,int b){
	if(cek(a) != cek(b)){
		cnt[cek(a)] += cnt[cek(b)];
		p[cek(b)] = cek(a);
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    REP(i,1,n)cin>>arr[i];
    
    REP(i,1,n)sorter.pb(mp(-arr[i], i));
    sort(sorter.begin(), sorter.end());
    
    REP(i,1,n)ans[i] = -1;
    REP(i,1,n)p[i] = i;
    REP(i,1,n)cnt[i] = 1;
    
    REP(i,0,n-1){
    	int now = sorter[i].ss;
    	
    	if(now > 1 && arr[now-1] >= arr[now]){
    		connect(now, now-1);
		}
		if(now < n && arr[now+1] >= arr[now]){
			connect(now, now+1);
		}
		
		int mx = cnt[cek(now)];
		ans[mx] = max(ans[mx], arr[now]);
	}
	
	REV(i,n-1,1)ans[i] = max(ans[i], ans[i+1]);
	REP(i,1,n)cout << ans[i] << " ";
	cout << endl;
    
    return 0;
}