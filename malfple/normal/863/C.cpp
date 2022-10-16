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

ll k;
int a,b;
int ma[5][5];
int mb[5][5];

ll dist[5][5];
ll pa[5][5];
ll pb[5][5];

int calc(int a, int b){
	if(a == 1 && b == 3)return 1;
	if(a == 2 && b == 1)return 1;
	if(a == 3 && b == 2)return 1;
	return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>k>>a>>b;
    REP(i,1,3)REP(j,1,3)cin>>ma[i][j];
    REP(i,1,3)REP(j,1,3)cin>>mb[i][j];
    
    dist[a][b] = 1;
    pa[a][b] = calc(a,b);
    pb[a][b] = calc(b,a);
    k--;
    while(k--){
    	int ta = a, tb = b;
    	a = ma[ta][tb];
    	b = mb[ta][tb];
    	
    	if(dist[a][b] != 0){
    		int sz = dist[ta][tb]+1 - dist[a][b];
    		ll r = k/sz;
    		ll ppa = pa[ta][tb] + calc(a,b) - pa[a][b];
    		ll ppb = pb[ta][tb] + calc(b,a) - pb[a][b];
    		
    		//printf("cycle %d %d %d %d\n",sz,r,ppa,ppb);
    		
    		k -= r*sz;
    		pa[a][b] = pa[ta][tb] + calc(a,b) + r*ppa;
    		pb[a][b] = pb[ta][tb] + calc(b,a) + r*ppb;
    		
    		REP(i,1,3){
    			REP(j,1,3){
    				if(i == a && j == b)continue;
    				dist[i][j] = 0;
				}
			}
		}else{
			dist[a][b] = dist[ta][tb]+1;
			pa[a][b] = pa[ta][tb] + calc(a,b);
			pb[a][b] = pb[ta][tb] + calc(b,a);
		}
		
		//printf("%d %d %d\n",k,pa[a][b],pb[a][b]);
	}
	
	cout << pa[a][b] << " " << pb[a][b] << endl;
    
    return 0;
}