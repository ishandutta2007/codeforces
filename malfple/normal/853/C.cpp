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

struct node{
    int v;
    node* lf;
    node* rg;
    node(int pv = 0, node* pl = NULL, node* pr = NULL) : v(pv), lf(pl), rg(pr){}
};

node* build_base(int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        return new node(0, build_base(left, mid), build_base(mid+1, right));
    }
    return new node();
}

node* add(node* prev, int left, int right, int x){
    if(left == right)return new node(prev->v+1);

    int mid = (left+right)/2;
    if(x <= mid)return new node(prev->v+1, add(prev->lf, left, mid, x), prev->rg);
    else return new node(prev->v+1, prev->lf, add(prev->rg, mid+1, right, x));
}

int qlower(node* a, node* b, int left, int right, int x){
    if(left > x)return 0;
    if(right <= x)return b->v - a->v;
    int mid = (left+right)/2;
    return qlower(a->lf, b->lf, left, mid, x) + qlower(a->rg, b->rg, mid+1, right, x);
}

int n,q;
node* head[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    head[0] = build_base(1,n);
    REP(i,1,n){
        int x;
        cin>>x;
        head[i] = add(head[i-1], 1, n, x);
    }

    /*while(1){
        int a,b,x;
        cin>>a>>b>>x;
        cout << qlower(head[a-1], head[b], 1, n, x) << endl;
    }*/

    REP(i,1,q){
        int l,d,r,u;
        cin>>l>>d>>r>>u;

        ll S = qlower(head[l-1], head[r], 1, n, d-1);
        ll N = r-l+1 - qlower(head[l-1], head[r], 1, n, u);

        ll SW = qlower(head[0], head[l-1], 1, n, d-1);
        ll NW = l-1 - qlower(head[0], head[l-1], 1, n, u);
        ll W = l-1 - NW - SW;

        ll SE = qlower(head[r], head[n], 1, n, d-1);
        ll NE = n-r - qlower(head[r], head[n], 1, n, u);
        ll E = n-r - SE - NE;

        //printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",NW,W,SW,N,S,NE,E,SE);

        ll ans = 0;
        ans += S*(S-1)/2;
        ans += N*(N-1)/2;
        ans += E*(E-1)/2;
        ans += W*(W-1)/2;

        ans += NW*(NW-1)/2;
        ans += NE*(NE-1)/2;
        ans += SE*(SE-1)/2;
        ans += SW*(SW-1)/2;

        ans += N*NW;
        ans += N*NE;
        ans += E*NE;
        ans += E*SE;
        ans += S*SE;
        ans += S*SW;
        ans += W*SW;
        ans += W*NW;

        ans += NW*NE;
        ans += NE*SE;
        ans += SE*SW;
        ans += SW*NW;

        cout << (ll)n*(n-1)/2 - ans << endl;
    }

    return 0;
}