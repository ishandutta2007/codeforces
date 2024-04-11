#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
struct segment_tree{
	int ls,rs,sum;
}t[maxn*20];
int cnt;
int insert(int p,int l,int r,int k){
	t[++cnt]=t[p];
	p=cnt;
	++t[p].sum;
	if(l==r)return p;
	ri mid=l+r>>1;
	if(k<=mid)t[p].ls=insert(t[p].ls,l,mid,k);
	else t[p].rs=insert(t[p].rs,mid+1,r,k);
	return p;
}
int lim;
int query(int p1,int p2,int l,int r){
	if(l==r)return l;
	ri d=t[t[p2].ls].sum-t[t[p1].ls].sum,mid=l+r>>1,ret=0;
	if(d>lim){
		ret=query(t[p1].ls,t[p2].ls,l,mid);
		if(ret>0)return ret;
	}
	if(t[p2].sum-t[p1].sum-d>lim){
		ret=query(t[p1].rs,t[p2].rs,mid+1,r);
		if(ret>0)return ret;
	}
	return -1;
}
int a[maxn],m,n,q,rt[maxn];
int main(){
	scanf("%d%d",&n,&q);
	m=n;
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		rt[i]=insert(rt[i-1],1,m,a[i]);
	}
	while(q--){
		ri ans,k,l,r;
		scanf("%d%d%d",&l,&r,&k);
		lim=(r-l+1)/k;
		ans=query(rt[l-1],rt[r],1,m);
		printf("%d\n",ans);
	}
	return 0;
}