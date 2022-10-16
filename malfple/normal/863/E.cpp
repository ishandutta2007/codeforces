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
int l[N], r[N];
map<int,int>mep;
int cntr;

int tree[6*N];
int query(int l, int r){
	int ret = OO;
	for(l += cntr-1, r += cntr; l<r; l>>=1, r>>=1){
		if(l&1)ret = min(ret, tree[l++]);
		if(r&1)ret = min(ret, tree[--r]);
	}
	return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    REP(i,1,n)cin>>l[i]>>r[i];
    
    REP(i,1,n){
    	mep[l[i]] = 0;
    	mep[r[i]] = 0;
    	mep[r[i]+1] = 0;
	}
	
	cntr = 0;
	for(map<int,int>::iterator it = mep.begin(); it != mep.end(); it++){
		it->ss = ++cntr;
	}
	REP(i,1,n){
		l[i] = mep[l[i]];
		r[i] = mep[r[i]];
	}
	
	REP(i,1,n){
		tree[cntr+l[i]-1]++;
		tree[cntr+r[i]]--;
	}
	REP(i,cntr+1,2*cntr)tree[i] += tree[i-1];
	REV(i,cntr-1,1)tree[i] = min(tree[i<<1], tree[i<<1|1]);
	
	//printf("cntr: %d\n",cntr);
	//REP(i,1,2*cntr)printf("%d ",tree[i]);printf("\n");
	
	int ans = -1;
	REP(i,1,n){
		//printf("query %d %d\n",l[i],r[i]);
		//printf("%d\n",query(l[i], r[i]));
		if(query(l[i], r[i]) > 1){
			ans = i;
			break;
		}
	}
	
	cout << ans << endl;
    
    return 0;
}