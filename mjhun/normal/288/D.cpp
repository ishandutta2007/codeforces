#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<int> g[80005];int n;
int s[80005];
ll r,pingo;

void dfs(int x, int p){
	s[x]=1;
	for(int y:g[x]){
		if(y==p)continue;
		dfs(y,x);
		s[x]+=s[y];
	}
	ll a=1,b=0,c=0,d=0;
	for(int y:g[x]){
		int t=s[y];
		if(y==p)t=n-s[x];
		d+=t*c;
		c+=t*b;
		b+=t*a;
		a+=t;
	}
	//printf("a %d %lld\n",x+1,r);
	r-=3*d;
	for(int y:g[x]){
		int t=s[y];
		if(y==p)t=n-s[x];
		pingo+=1LL*(b-t*(n-t))*t*(t-1)/2*2;
		pingo+=1LL*(b-t*(n-t))*t;
		pingo+=1LL*t*(t-1)/2;
	}
	a=0,b=0;
	for(int y:g[x]){
		int t=s[y];
		if(y==p)t=n-s[x];
		b+=t*a;
		a+=t;
	}
	r-=b;
	//a=1,b=0;
	//for(int y:g[x]){
	//	int t=s[y];
	//	if(y==p)continue;
	//	b+=t*a;
	//	a+=t;
	//}
	//printf("asd %d %lld\n",x+1,r);
	//r-=1LL*(n-s[x])*(n-s[x]-1)*b;
	//r-=1LL*(n-s[x])*b;
	//r-=1LL*(n-s[x])*(n-s[x]-1)/2*(s[x]-1);
	//printf("b %d %lld\n",x+1,r);
}

int main(){
	scanf("%d",&n);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	ll p=1LL*n*(n-1)/2;
	ll p2=p-1;
	if(p%2==0)p/=2;
	if(p2%2==0)p2/=2;
	r=p*p2;
	dfs(0,-1);
	r-=pingo/2;
	r*=2;
	printf("%lld\n",r);
	return 0;
}