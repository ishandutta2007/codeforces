#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex> 

#pragma warning(disable:4996) 

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define pb push_back 
#define mp make_pair 
#define x first 
#define y second 
#define all(v) (v).begin(),(v).end() 

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-4;
const double PI=3.1415926535897932384626433832795;

vector<pair<ll,ll>> v;

ll dist(pair<ll,ll> a,pair<ll,ll> b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void solve(){
	int n;
	ll x1,x2,y1,y2,a,b;
	pair<ll,ll> c1,c2;
	scanf("%d%I64d%I64d%I64d%I64d",&n,&x1,&y1,&x2,&y2);
	c1=mp(x1,y1);
	c2=mp(x2,y2);
	For(i,n){
		scanf("%I64d%I64d",&a,&b);
		v.pb(mp(a,b));
	}
	ll ans=LONGINF;
	ll t=0;
	For(i,n) t=max(t,dist(c1,v[i]));
	ans=min(ans,t);
	t=0;
	For(i,n) t=max(t,dist(c2,v[i]));
	ans=min(ans,t);
	For(i,n){
		ll r1=dist(c1,v[i]);
		ll r2=0;
		For(j,n){
			if(dist(c1,v[j])>r1) r2=max(r2,dist(c2,v[j]));
		}
		ans=min(ans,r1+r2);

	}
	printf("%I64d",ans);
}

int main(){
#pragma comment(linker,"/STACK:268435456") 
#ifdef _DEBUG 
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	solve();
	return 0;
}