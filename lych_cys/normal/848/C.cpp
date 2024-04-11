#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 15000005
using namespace std;

int n,m,trtot,a[N],ls[M],rs[M],rt[N]; ll sum[M];
set<int> S[N]; set<int> :: iterator it;
void ins(int &k,int l,int r,int x,int y){
	if (!k) k=++trtot;
	sum[k]+=y; if (l==r) return;
	int mid=l+r>>1;
	if (x<=mid) ins(ls[k],l,mid,x,y); else ins(rs[k],mid+1,r,x,y);
}
ll qry(int k,int l,int r,int x){
	if (!k) return 0;
	if (l==r) return sum[k];
	int mid=l+r>>1;
	if (x<=mid) return qry(ls[k],l,mid,x);
		else return sum[ls[k]]+qry(rs[k],mid+1,r,x);
}
void add(int x,int y,int z){
	if (y<=n) for (; x<=n; x+=x&-x) ins(rt[x],1,n,y,z);
}
ll getsum(int x,int y){
	ll z=0;
	if (y>0) for (; x; x^=x&-x) z+=qry(rt[x],1,n,y);
	return z;
}
void add(int x1,int x2,int y1,int y2,int z){
	if (x1>x2 || y1>y2) return;
	//cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<' '<<z<<endl;
	add(x1,y1,z);
	add(x1,y2+1,-z);
	add(x2+1,y1,-z);
	add(x2+1,y2+1,z);
}
ll getsum(int x1,int x2,int y1,int y2,int z){
	if (x1>x2 || y1>y2) return 0;
	return getsum(x2,y2)+getsum(x1-1,y1-1)-getsum(x2,y1-1)-getsum(x1-1,y2);
}
void jiaru(int x,int y){
	it=S[x].lower_bound(y); int l,r;
	r=(*it); it--; l=(*it);
	//cout<<y<<' '<<l<<' '<<r<<endl;
	add(l+1,y,r,n,r-y); add(1,l,y,r-1,y-l);
	S[x].insert(y);
}
void shanchu(int x,int y){
	it=S[x].upper_bound(y); int l,r;
	r=(*it); it--; it--; l=(*it);
	add(l+1,y,r,n,y-r); add(1,l,y,r-1,l-y);
	S[x].erase(y);
}
int main(){
	scanf("%d%d",&n,&m);
	int i,x,y;
	for (i=1; i<=n; i++){
		S[i].insert(0); S[i].insert(n+1);
	}
	for (i=1; i<=n; i++){
		scanf("%d",&a[i]);
		jiaru(a[i],i);
	}
	//puts("---------");
	while (m--){
		scanf("%d%d%d",&i,&x,&y);
		if (i==1){
			shanchu(a[x],x); a[x]=y; jiaru(y,x);
		} else printf("%lld\n",getsum(x,y));
	}
	return 0;
}