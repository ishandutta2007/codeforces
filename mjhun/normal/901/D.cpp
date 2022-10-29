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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int ex[100005],ey[100005];
vector<int> g[100005];
int n,m,c[100005];
ll a[100005],r[100005],s[2];
vector<int> g2[100005];

void dfs0(int x){
	s[c[x]]+=a[x];
	for(int i:g[x]){
		int y=ex[i]^ey[i]^x;
		if(c[y]<0){
			c[y]=1-c[x];
			g2[x].pb(i);g2[y].pb(i);
			dfs0(y);
		}
	}
}

void dfs1(int x, int f){
	for(int i:g2[x]){
		int y=ex[i]^ey[i]^x;
		if(y==f)continue;
		dfs1(y,x);
		r[i]=a[y];
		a[x]-=r[i];
	}
}

int main(){
	scanf("%d%d",&n,&m);
	ll ss=0;
	fore(i,0,n)scanf("%lld",a+i),ss+=a[i];
	fore(i,0,m){
		scanf("%d%d",ex+i,ey+i);ex[i]--;ey[i]--;
		g[ex[i]].pb(i);g[ey[i]].pb(i);
	}
	memset(c,-1,sizeof(c));c[0]=0;dfs0(0);
	fore(i,0,m)if(c[ex[i]]==c[ey[i]]){
		r[i]=(s[c[ex[i]]]-s[c[ex[i]]^1])/2;
		a[ex[i]]-=r[i];
		a[ey[i]]-=r[i];
		s[c[ex[i]]]-=2*r[i];
		break;
	}
	if(s[0]!=s[1]){puts("NO");return 0;}
	dfs1(0,-1);
	puts("YES");
	fore(i,0,m)printf("%lld\n",r[i]);
	return 0;
}