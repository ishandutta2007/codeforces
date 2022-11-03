#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define LD long double
#define N 200005
#define pii pair<int,int>

int t[N*4],g[N*4],tn,n,m,tt[N*4],gg[N*4];
LL h[N],s[N];

inline bool cmp1(const int &l,const int &r){
	if(l==0) return 0;
	if(r==0) return 1;
	return 2*h[l]+s[l]>2*h[r]+s[r];
}
inline bool cmp2(const int &l,const int &r){
	if(l==0) return 0;
	if(r==0) return 1;
	return 2*h[l]-s[l]>2*h[r]-s[r];
}

pii getmaxt(int x,int l,int r,int a,int b){
	if(l==a && b==r) return pii(t[x],tt[x]);
	int mid=l+r>>1;
	if(b<=mid) return getmaxt(x<<1,l,mid,a,b);
	if(a>mid) return getmaxt(x<<1|1,mid+1,r,a,b);
	pii u=getmaxt(x<<1,l,mid,a,mid);
	pii v=getmaxt(x<<1|1,mid+1,r,mid+1,b);
	if(cmp1(u.first,v.first)){
		if(cmp1(u.second,v.first)) return u;
		return pii(u.first,v.first);
	}else{
		if(cmp1(u.first,v.second)) return pii(v.first,u.first);
		return v;
	}
}

pii getmaxg(int x,int l,int r,int a,int b){
	if(l==a && b==r) return pii(g[x],gg[x]);
	int mid=l+r>>1;
	if(b<=mid) return getmaxg(x<<1,l,mid,a,b);
	if(a>mid) return getmaxg(x<<1|1,mid+1,r,a,b);
	pii u=getmaxg(x<<1,l,mid,a,mid);
	pii v=getmaxg(x<<1|1,mid+1,r,mid+1,b);
	if(cmp2(u.first,v.first)){
		if(cmp2(u.second,v.first)) return u;
		return pii(u.first,v.first);
	}else{
		if(cmp2(u.first,v.second)) return pii(v.first,u.first);
		return v;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,2,n) scanf("%I64d",s+i);
	scanf("%I64d",s+1);
	rep(i,1,n) scanf("%I64d",h+i);
	rep(i,n+1,n<<1) s[i]=s[i-n],h[i]=h[i-n];
	rep(i,1,n<<1) s[i]+=s[i-1];
	for(tn=1;tn<n<<1;tn<<=1);
	rep(i,tn,tn+n*2-1) t[i]=i-tn+1,g[i]=i-tn+1;
	dep(i,tn-1,1){
		int l=t[i<<1],r=t[i<<1|1],ll=tt[i<<1],rr=tt[i<<1|1];
		if(cmp1(l,r)){
			t[i]=l;
			if(cmp1(ll,r)) tt[i]=ll;
			else tt[i]=r;
		}else{
			t[i]=r;
			if(cmp1(l,rr)) tt[i]=l;
			else tt[i]=rr;
		}
		l=g[i<<1],r=g[i<<1|1],ll=gg[i<<1],rr=gg[i<<1|1];
		if(cmp2(l,r)){
			g[i]=l;
			if(cmp2(ll,r)) gg[i]=ll;
			else gg[i]=r;
		}else{
			g[i]=r;
			if(cmp2(l,rr)) gg[i]=l;
			else gg[i]=rr;
		}
	}
	while(m--){
		int x,y;
		pii l,r;
		scanf("%d%d",&x,&y);
		if(y<x){
			if(y+1==x || y+2==x){puts("0");continue;}
			l=getmaxg(1,1,tn,y+1,x-1);
			r=getmaxt(1,1,tn,y+1,x-1);
		}else{
			if(x==1 && y==n || x==2 && y==n || x==1 && y==n-1){puts("0");continue;}
			l=getmaxg(1,1,tn,y+1,x+n-1);
			r=getmaxt(1,1,tn,y+1,x+n-1);
		}
		if(l.first^r.first)	printf("%I64d\n",s[r.first]-s[l.first]+2*h[l.first]+2*h[r.first]);
		else printf("%I64d\n",max(s[r.first]-s[l.second]+2*h[l.second]+2*h[r.first],
		s[r.second]-s[l.first]+2*h[l.first]+2*h[r.second]));
	}
}