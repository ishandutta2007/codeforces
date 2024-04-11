#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define dbg(...) printf(__VA_ARGS__);
#define getchar_unlocked getchar
#else
#define dbg(...)
#endif
#define sf scanf
#define pf printf
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define mnto(x,y) x=min(x,(__typeof__(x))y)
#define mxto(x,y) x=max(x,(__typeof__(x))y)
#define INF 1023456789
#define LINF 1023456789123456789
#define all(x) x.begin(), x.end()
#define disc(x) sort(all(x));x.resize(unique(all(x))-x.begin());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pll> vll;
mt19937 rng(time(0));

#define mod 1000000007

inline int add(int a,int b){
	int r=a+b;
	while(r>=mod)r-=mod;
	while(r<0)r+=mod;
	return r;
}

inline int mult(int a,int b){
	return (int)(((ll)(a*b))%mod);
}

int scan(int a,int b){
	pf("SCAN %d %d\n",a,b);
	fflush(stdout);
	int x;sf("%d",&x);
	return x;
}

int dig(int a,int b){
	pf("DIG %d %d\n",a,b);
	fflush(stdout);
	int x;sf("%d",&x);
	return x;
}

void solve(){
	int n,m;sf("%d%d",&n,&m);
	int a=scan(1,1)+4;//r1-1+r2-1+c1-1+c2-1+4=r1+r2+c1+c2
	int b=scan(1,m)+2-2*m;//r1-1+r2-1+m-c1+m-c2=r1+r2-c1-c2
	int sr=(a+b)/2;//r1+r2
	int sc=(a-b)/2;//c1+c2
	int c=scan(sr/2,1)+2;//x-r1+r2-x+c1-1+c2-1+2=r2-r1+c1+c2
	int r1=(sr-c+sc)/2,r2=(c-sc+sr)/2;
	int d=scan(1,sc/2)+2;//r1-1+r2-1+x-c1+c2-x+2=r1+r2-c1+c2
	int c1=(sr-d+sc)/2,c2=(d-sr+sc)/2;
	if(dig(r1,c1))dig(r2,c2);
	else dig(r1,c2),dig(r2,c1);
}

int main(){
	int t;sf("%d",&t);
	while(t--)solve();
}