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

int n,m,k;
map<int,vector<pair<int,int> > > ex,ey;
map<int,vector<pair<int,int> > > wx,wy;
map<int,int> lx,ly;

void doit(map<int,vector<pair<int,int> > >& e, map<int,vector<pair<int,int> > >& w, map<int,int>& l, int n){
	for(auto _:e){
		int x=_.fst;
		int q=0,z;
		sort(_.snd.begin(),_.snd.end());
		l[x]=n;
		for(auto p:_.snd){
			q+=p.snd;
			if(p.snd>0&&q==1)z=p.fst;
			else if(q==0)w[x].pb(mp(z,p.fst)),l[x]-=p.fst-z;
		}
	}
}

int doit2(vector<pair<int,int> > w, int x){
	int l=0;
	for(auto p:w){
		if(l+x<=p.fst)return l+x;
		x-=p.fst-l;
		l=p.snd;
	}
	return l+x;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(_,0,k){
		int x0,y0,x1,y1;
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		if(x0>x1)swap(x0,x1);
		if(y0>y1)swap(y0,y1);
		if(y0==y1)ey[y0].pb(mp(x0,1)),ey[y0].pb(mp(x1,-1));
		else ex[x0].pb(mp(y0,1)),ex[x0].pb(mp(y1,-1));
	}
	doit(ex,wx,lx,m);
	doit(ey,wy,ly,n);
	int r=0;
	for(auto p:lx)r^=p.snd;
	for(auto p:ly)r^=p.snd;
	if((n-1-SZ(lx))%2)r^=m;
	if((m-1-SZ(ly))%2)r^=n;
	puts(r?"FIRST":"SECOND");
	if(r){
		int x0=-1,y0,x1,y1;
		for(auto p:lx)if((p.snd^r)<p.snd){
			x0=x1=p.fst;
			y0=0;y1=doit2(wx[p.fst],p.snd-(p.snd^r));
			break;
		}
		if(x0<0)for(auto p:ly)if((p.snd^r)<p.snd){
			y0=y1=p.fst;
			x0=0;x1=doit2(wy[p.fst],p.snd-(p.snd^r));
			break;
		}
		if(x0<0&&(n-1-SZ(lx))%2&&(m^r)<m){
			x0=1;
			while(lx.count(x0))x0++;
			x1=x0;
			y0=0;y1=m-(m^r);
		}
		if(x0<0&&(m-1-SZ(ly))%2&&(n^r)<n){
			y0=1;
			while(ly.count(y0))y0++;
			y1=y0;
			x0=0;x1=n-(n^r);
		}
		assert(x0>=0);
		printf("%d %d %d %d\n",x0,y0,x1,y1);
	}
	return 0;
}