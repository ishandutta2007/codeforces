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

#define MOD 1000000007

int uf[1<<19];
int n,m;
ll v[1<<19];
int p2[1<<19];
map<ll,vector<pair<int,int> > > w;
int kk;

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

void join(int x, int y){
	assert(x!=y&&uf[x]<0&&uf[y]<0);
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
}

int main(){
	p2[0]=1;
	fore(i,1,(1<<19)){
		p2[i]=p2[i-1]*2;
		if(p2[i]>=MOD)p2[i]-=MOD;
	}
	scanf("%d%d%d",&n,&m,&kk);
	fore(i,0,n)scanf("%lld",v+i);
	fore(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		w[v[x]^v[y]].pb(mp(x,y));
	}
	int r=0;
	mset(uf,-1);
	for(auto _:w){
		auto v=_.snd;
		int q=n;
		for(auto p:v){
			int x=p.fst,y=p.snd;
			x=find(x);y=find(y);
			if(x!=y){
				join(x,y);
				q--;
			}
		}
		for(auto p:v){
			int x=p.fst,y=p.snd;
			uf[x]=uf[y]=-1;
		}
		r+=p2[q];
		if(r>=MOD)r-=MOD;
	}
	r+=1LL*(((1LL<<kk)-SZ(w))%MOD)*p2[n]%MOD;
	if(r>=MOD)r-=MOD;
	printf("%d\n",r);
	return 0;
}