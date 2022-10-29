#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

vector<int> uf[200005];
vector<pair<int,int> > h[200005];
vector<pair<int,int> > e;
int c[200005];
int w[200005];
int a[200005];
int b[200005];
int z[200005];
int n,m,S;

int findt(int x, int y){
	// primer tiempo en el que son iguales
	int s=1,e=n+2;
	while(e-s>1){
		int m=(s+e)/2;
		//ver si en m-1 son iguales
		int i=upper_bound(h[x].begin(),h[x].end(),mp(m-1,1<<20))-h[x].begin()-1;
		int j=upper_bound(h[y].begin(),h[y].end(),mp(m-1,1<<20))-h[y].begin()-1;
		if(h[x][i].snd==h[y][j].snd)e=m;
		else s=m;
	}
	return s;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m)scanf("%d",w+i);
	fore(i,0,m)scanf("%d",c+i);
	fore(i,0,m){
		scanf("%d%d",a+i,b+i);a[i]--;b[i]--;
		if(a[i]>b[i])swap(a[i],b[i]);
	}
	scanf("%d",&S);
	fore(i,0,n)uf[i].pb(i);
	fore(i,0,n)h[i].pb(mp(0,i));
	fore(i,0,m)e.pb(mp(w[i],i));
	sort(e.begin(),e.end());
	int t=1;
	ll s=0;
	fore(_,0,e.size()){
		int i=e[_].snd;
		int x=a[i],y=b[i];
		if(x==y)continue;
		int fx=h[x].back().snd,fy=h[y].back().snd;
		if(fx==fy)continue;
		z[t]=i;  // cual elegi en tal tiempo
		s+=w[i];
		if(uf[fx].size()<uf[fy].size()){
			swap(fx,fy);
			swap(x,y);
		}
		fore(j,0,uf[fy].size()){
			h[uf[fy][j]].pb(mp(t,fx));
			uf[fx].pb(uf[fy][j]);
		}
		uf[fy].clear();
		t++;
	}
	assert(t==n);
	ll r0=1LL<<62;
	int r1=-1;
	fore(i,0,m){
		if(a[i]==b[i])continue;
		int t=findt(a[i],b[i]); // primer tiempo en el que son iguales
		ll rr=s-w[z[t]]+w[i]-S/c[i];
		if(rr<r0){
			r0=rr;
			r1=i;
		}
	}
	printf("%lld\n",r0);
	t=findt(a[r1],b[r1]);
	fore(i,1,n){
		if(i==t)continue;
		printf("%d %d\n",z[i]+1,w[z[i]]);
	}
	printf("%d %d\n",r1+1,w[r1]-S/c[r1]);
	return 0;
}