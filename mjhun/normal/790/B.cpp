#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,k;
vector<int> g[200005];
//int h[200005];
ll r;

pair<vector<int>,vector<ll> > shift(pair<vector<int>,vector<ll> > p){
	vector<int> r0(k,0);
	vector<ll> r1(k,0);
	fore(i,0,k){
		r0[(i+1)%k]=p.fst[i];
		r1[(i+1)%k]=p.snd[i];
	}
	r1[1%k]+=r0[1%k];
	return mp(r0,r1);
}

pair<vector<int>,vector<ll> > dfs(int x, int f){
	vector<int> r0(k,0);
	vector<ll> r1(k,0);
	if(g[x].size()==1&&g[x][0]==f){
		r0[0]=1;
		return mp(r0,r1);
	}
	r0[0]=1;
	for(int y:g[x]){
		if(y==f)continue;
		auto p=dfs(y,x);
		p=shift(p);
		//puts("hola");fore(i,0,k)printf("%d  %d %lld\n",i,p.fst[i],p.snd[i]);puts("");
		//fore(i,0,k)r+=r1[i];
		fore(i,0,k)fore(j,0,k){
			r+=r0[i]*p.snd[j];
			r+=r1[i]*p.fst[j];
			if(i&&j&&i+j<=k)r-=1LL*r0[i]*p.fst[j];
		}
		fore(i,0,k)r0[i]+=p.fst[i];
		fore(i,0,k)r1[i]+=p.snd[i];
	}
	//printf(" %d\n",x+1);fore(i,0,k)printf("%d  %d %lld\n",i,r0[i],r1[i]);puts("");
	return mp(r0,r1);
}

int main(){
	scanf("%d%d",&n,&k);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	dfs(0,-1);
	printf("%lld\n",r);
	return 0;
}