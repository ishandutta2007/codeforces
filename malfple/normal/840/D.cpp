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

//end of macro

const int N = 3e5 + 5;

struct node{
	int v;
	int l;
	int r;
	
	node(int pv = 0, int pl = -1, int pr = -1){
		v = pv;
		l = pl;
		r = pr;
	}
};

int n,q;
int head[N];
node pyon[N * 22];
int cntr;

int build(int l,int r){
	int ret = ++cntr;
	if(l<r){
		int m = (l+r)>>1;
		pyon[ret].l = build(l, m);
		pyon[ret].r = build(m+1, r);
	}
	return ret;
}

int add(int prev, int l, int r, int x){
	if(x < l || x > r)return prev;
	int ret = ++cntr;
	pyon[ret] = pyon[prev].v + 1;
	if(l < r){
		int m = (l+r)>>1;
		pyon[ret].l = add(pyon[prev].l, l, m, x);
		pyon[ret].r = add(pyon[prev].r, m+1, r, x);
	}
	return ret;
}

int query(int a, int b, int l, int r, int lim){
	if(l == r)return l;
	
	int m = (l+r)>>1;
	int ret = -1;
	int vl = pyon[pyon[b].l].v - pyon[pyon[a].l].v;
	if(vl >= lim)ret = query(pyon[a].l, pyon[b].l, l, m, lim);
	
	if(ret != -1)return ret;
	
	int vr = pyon[pyon[b].r].v - pyon[pyon[a].r].v;
	if(vr >= lim)ret = query(pyon[a].r, pyon[b].r, m+1, r, lim);
	return ret;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    
    ini(n);ini(q);//scanf("%d %d",&n,&q);//cin>>n>>q;
    head[0] = build(1,n);
    REP(i,1,n){
    	int x;ini(x);//scanf("%d",&x);//cin>>x;
    	head[i] = add(head[i-1], 1, n, x);
	}
	
	while(q--){
		int a,b,c;
		ini(a),ini(b),ini(c);//scanf("%d %d %d",&a,&b,&c);//cin>>a>>b>>c;
		int lim = (b-a+1)/c + 1;
		printf("%d\n",query(head[a-1], head[b], 1, n, lim));//cout << query(head[a-1], head[b], 1, n, lim) << endl;
	}
    
    return 0;
}