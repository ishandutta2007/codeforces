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

int uf[4];

void uf_init(){
	fore(i,0,4)uf[i]=-1;
}
int find(int x){
	while(uf[x]>=0)x=uf[x];
	return x;
}
void join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)return;
	uf[x]=y;
}

int n,m;
int x[16],y[16];
int id[4][4];
int d[4];
vector<int> w[16];

int main(){
	fore(i,0,4)fore(j,i,4){
		id[i][j]=m;
		x[m]=i;y[m]=j;
		m++;
	}
	scanf("%d",&n);
	fore(i,0,n){
		int x,c,y;
		scanf("%d%d%d",&x,&c,&y);x--;y--;
		if(x>y)swap(x,y);
		w[id[x][y]].pb(c);
	}
	fore(i,0,16)sort(w[i].begin(),w[i].end());
	ll r=0;
	fore(mm,0,1<<(2*m)){
		bool val=true;
		fore(i,0,m)val=val&&(((mm>>(2*i))&3)<3);
		if(!val)continue;
		fore(i,0,4)d[i]=0;
		uf_init();
		ll s=0;
		fore(i,0,m){
			int t=(mm>>(2*i))&3;
			if(t>SZ(w[i])){val=false;break;}
			if(!t)continue;
			fore(j,0,SZ(w[i]))s+=w[i][j];
			if(SZ(w[i])%2!=t%2)s-=w[i][0];
			d[x[i]]+=t;
			d[y[i]]+=t;
			join(x[i],y[i]);
		}
		if(!val)continue;
		int t=-1;
		fore(i,0,4){
			if(!d[i])continue;
			if(t<0)t=i;
			else if(find(t)!=find(i))val=false;
		}
		t=0;
		fore(i,0,4)t+=d[i]%2;
		if(t>2)val=false;
		if(!val)continue;
		r=max(r,s);
	}
	printf("%lld\n",r);
	return 0;
}