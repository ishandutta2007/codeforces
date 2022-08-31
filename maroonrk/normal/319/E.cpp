#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
	
using namespace std;

typedef pair<int,int> pii;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int Nmax=100000;
const int SegMax=1<<18;

struct UnionFind{
	int par[Nmax],rank[Nmax];
	void Init(int n){
		fill(par,par+n,-1);
		fill(rank,rank+n,0);
	}
	int Find(int a){
		if(par[a]==-1)
			return a;
		else
			return par[a]=Find(par[a]);
	}
	bool Same(int a,int b){
		return Find(a)==Find(b);
	}
	void Unite(int a,int b){
		a=Find(a);
		b=Find(b);
		if(a==b)
			return;
		if(rank[a]<rank[b])
			par[a]=b;
		else{
			par[b]=a;
			if(rank[a]==rank[b])
				rank[a]++;
		}
	}
} uf;

struct Query{
	int t,x,y;
} qs[Nmax];

int xs[Nmax],xCount=1;

struct Interval{
	int x,y,i;
	bool operator<(const Interval& rhs)const{
		if(y!=rhs.y)
			return y<rhs.y;
		else
			return i<rhs.i;
	}
} listBuf[Nmax],nowItvl[Nmax];

struct Seg{
	int s;
	set<Interval> yi[SegMax];
	void Init(){
		s=1;
		while(s<xCount)s*=2;
	}
	void ListUp(int b,int e,int l,int r,int i,int y,Interval* dst,int& len){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e){
			auto itr=yi[i].lower_bound(Interval{0,y,INT_MAX});
			while(itr!=yi[i].end())
				dst[len++]=*itr++;
			return;
		}
		ListUp(b,e,l,(l+r)/2,i*2,y,dst,len);
		ListUp(b,e,(l+r)/2,r,i*2+1,y,dst,len);
	}
	void ListUp(int x,Interval* dst,int& len){
		int e=lower_bound(xs,xs+xCount,x)-xs;
		ListUp(0,e,0,s,1,x,dst,len);
	}
	void Add(Interval p){
		int i=lower_bound(xs,xs+xCount,p.x)-xs;
		i+=s;
		while(i>=1){
			yi[i].insert(p);
			i/=2;
		}
	}
	void Remove(Interval p){
		int i=lower_bound(xs,xs+xCount,p.x)-xs;
		i+=s;
		while(i>=1){
			yi[i].erase(p);
			i/=2;
		}
	}
} seg;

void Merge(int x,Interval& p){
	int len=0;
	seg.ListUp(x,listBuf,len);
	REP(i,len){
		uf.Unite(p.i,listBuf[i].i);
		p.x=min(p.x,listBuf[i].x);
		p.y=max(p.y,listBuf[i].y);
		seg.Remove(listBuf[i]);
	}
}

int main(){
	int n=read(),c=0;
	REP(i,n){
		qs[i].t=read(),qs[i].x=read(),qs[i].y=read();
		if(qs[i].t==1){
			xs[c]=qs[i].x;
			nowItvl[c]=Interval{qs[i].x,qs[i].y,c};
			c++;
		}else
			qs[i].x--,qs[i].y--;
	}
	sort(xs,xs+c);
	FOR(i,1,c)
		if(xs[xCount-1]!=xs[i])
			xs[xCount++]=xs[i];
	seg.Init();
	uf.Init(c);
	c=0;
	REP(i,n){
		if(qs[i].t==1){
			Interval p=nowItvl[c++];
			int px=p.x,py=p.y;
			Merge(px,p);
			Merge(py,p);
			seg.Add(p);
			nowItvl[uf.Find(p.i)]=p;
		}else{
			if(uf.Same(qs[i].x,qs[i].y))
				printf("YES\n");
			else{
				int fx=nowItvl[uf.Find(qs[i].x)].x,fy=nowItvl[uf.Find(qs[i].x)].y;
				int tx=nowItvl[uf.Find(qs[i].y)].x,ty=nowItvl[uf.Find(qs[i].y)].y;
				if((tx<fx&&fx<ty)||(tx<fy&&fy<ty))
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
}