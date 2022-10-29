#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define mset(a,v) memset(a,v,sizeof(a))
using namespace std;
typedef long long ll;

#define MAXN (1<<20)
vector<int> g[MAXN];int n;
int a[MAXN];ll r;
pair<int,int> aa[MAXN];
int uf[MAXN];bool w[MAXN];

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

void join(int x, int y){
	int c=max(a[x],a[y]);
	x=find(x);y=find(y);
	if(x==y)return;
	if(uf[x]>uf[y])swap(x,y);
	r+=1LL*c*uf[x]*uf[y];
	uf[x]+=uf[y];
	uf[y]=x;
}

void doit(){
	mset(uf,-1);mset(w,false);
	fore(i,0,n)aa[i]=mp(a[i],i);
	sort(aa,aa+n);
	fore(i,0,n){
		int x=aa[i].snd;
		w[x]=true;
		for(int y:g[x])if(w[y])join(x,y);
	}
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	doit();
	fore(i,0,n)a[i]*=-1;
	doit();
	printf("%lld\n",r);
	return 0;
}