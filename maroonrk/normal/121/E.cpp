#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MT make_tuple
	
const int SegMax=1<<17;
const int Inf=1145141919;

struct SegTree{
	int mn[SegMax*2],lz[SegMax*2];
	int s;
	void Init(int n){
		s=1;
		while(s<n)s*=2;
		fill(mn+s,mn+s+n,0);
		fill(mn+s+n,mn+s*2,Inf);
		for(int i=s-1;i>0;i--)
			mn[i]=min(mn[i*2],mn[i*2+1]);
		fill(lz,lz+s*2,0);
	}
	int Get(int i){
		return mn[i]+lz[i];
	}
	void Propagate(int i){
		mn[i]+=lz[i];
		lz[i*2]+=lz[i];
		lz[i*2+1]+=lz[i];
		lz[i]=0;
	}
	void Add(int b,int e,int l,int r,int v,int i){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e){
			lz[i]+=v;
			return;
		}
		Propagate(i);
		Add(b,e,l,(l+r)/2,v,i*2);
		Add(b,e,(l+r)/2,r,v,i*2+1);
		mn[i]=min(Get(i*2),Get(i*2+1));
	}
	void Add(int b,int e,int v){
		Add(b,e,0,s,v,1);
	}
	int LowerBound(int l,int r,int v,int i){
		if(r-l==1)
			return v<=Get(i)?l:r;
		Propagate(i);
		if(v<=Get(i*2+1))
			return LowerBound(l,(l+r)/2,v,i*2);
		else
			return LowerBound((l+r)/2,r,v,i*2+1);
	}
	int LowerBound(int v){
		return LowerBound(0,s,v,1);
	}
} seg;

struct BITree{
	int d[100000];
	int s;
	void Init(int n){
		s=n;
		fill(d,d+s,0);
	}
	void Add(int i,int v){
		while(i<s){
			d[i]+=v;
			i+=(i+1)&(-i-1);
		}
	}
	int Get(int i){
		int ret=0;
		while(i>=0){
			ret+=d[i];
			i-=(i+1)&(-i-1);
		}
		return ret;
	}
} bit;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

int arr[100000];

int lucky[]={
	4,7,
	44,47,74,77,
	444,447,474,477,744,747,774,777,
	4444,4447,4474,4477,4744,4747,4774,4777,
	7444,7447,7474,7477,7744,7747,7774,7777,};

struct Query{
	int t,x,y,v;
} q1[200000+100000],q2[100000*2*30+100000];

int main(){
	int n=read(),m=read();
	REP(i,n)
		arr[i]=read();
	int qs1=0,qs2=0;
	char str[16];
	REP(i,m){
		scanf("%s",str);
		if(strcmp(str,"add")==0){
			int l=read()-1,r=read(),d=read();
			q1[qs1++]=Query{1,l,i,d};
			q1[qs1++]=Query{1,r,i,-d};
		}else{
			int l=read()-2,r=read()-1;
			q2[qs2++]=Query{2,l,i,r};
		}
	}
	REP(i,n)
		q1[qs1++]=Query{2,i};
	sort(q1,q1+qs1,
	[](const Query& a,const Query& b)->bool{
		if(a.x!=b.x)
			return a.x<b.x;
		return a.t<b.t;
	});
	int mx=0;
	seg.Init(m);
	REP(i,qs1){
		if(q1[i].t==1){
			seg.Add(q1[i].y,m,q1[i].v);
			mx+=q1[i].v;
		}else{
			for(auto v:lucky){
				if(v<arr[q1[i].x])
					continue;
				if(v>arr[q1[i].x]+mx)
					continue;
				int l=seg.LowerBound(v-arr[q1[i].x]);
				int r=seg.LowerBound(v-arr[q1[i].x]+1);
				if(r>l){
					q2[qs2++]=Query{1,q1[i].x,l,1};
					q2[qs2++]=Query{1,q1[i].x,r,-1};
				}
			}
		}
	}
	sort(q2,q2+qs2,
	[](const Query& a,const Query& b)->bool{
		if(a.y!=b.y)
			return a.y<b.y;
		return a.t<b.t;
	});
	bit.Init(n);
	REP(i,qs2){
		if(q2[i].t==1)
			bit.Add(q2[i].x,q2[i].v);
		else{
			int c=bit.Get(q2[i].v)-bit.Get(q2[i].x);
			printf("%d\n",c);
		}
	}
}