#include <bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000ll
#define N 100005
using namespace std;

bool bj=0;
int n,m,ans,tmp,a[N],b[N],q[N]; ll s1[N],s2[N];
struct node{ ll icr,num,mn,mx,val; }P[N<<2];
void mdy(int k,ll x){
	node &o=P[k];
	o.icr+=x; o.mx+=x; o.mn+=x; o.val+=x;
}
void pushdn(int k){
	if (P[k].icr){
		mdy(k<<1,P[k].icr); mdy(k<<1|1,P[k].icr);
		P[k].icr=0;
	}
}
ll work(int k,int l,int r,ll x){
	if (l==r) return P[k].num+x;
	int mid=l+r>>1;
	pushdn(k);
	if (x>=P[k<<1].mx) return min(P[k<<1].num+x,work(k<<1|1,mid+1,r,max(x,P[k<<1].mx)));
		else return min(work(k<<1,l,mid,x),P[k].val);
}
void maintain(int k,int l,int r){
	node &o=P[k],&u=P[k<<1],&v=P[k<<1|1];
	o.mx=max(u.mx,v.mx); o.mn=min(u.mn,v.mn); o.num=min(u.num,v.num);
	int mid=l+r>>1;
	o.val=work(k<<1|1,mid+1,r,u.mx);
}
void ins(int k,int l,int r,int x,ll y){
	if (x<=l){
		mdy(k,y); return;
	}
	int mid=l+r>>1;
	pushdn(k);
	if (x<=mid) ins(k<<1,l,mid,x,y); ins(k<<1|1,mid+1,r,x,y);
	maintain(k,l,r);
}
ll getmax(int k,int l,int r,int x){
	if (x>r) return -inf;
	if (x<=l) return P[k].mx;
	int mid=l+r>>1;
	pushdn(k);
	return (x>mid)?getmax(k<<1|1,mid+1,r,x):max(getmax(k<<1,l,mid,x),P[k<<1|1].mx);
}
void qry(int k,int l,int r,int x,int y,ll z){
	if (x<=l && r<=y)
		if (work(k,l,r,z)>m) return;
	if (l==r){
		tmp=max(tmp,l); return;
	}
	int mid=l+r>>1;
	pushdn(k);
	if (y>mid) qry(k<<1|1,mid+1,r,x,y,max(z,getmax(k<<1,l,mid,x)));
	if (x<=mid && mid>=tmp) qry(k<<1,l,mid,x,y,z); 
}
int getrg(int k,int l,int r){
	if (l==r) return (P[k].mn<=m)?l:0;
	int mid=l+r>>1;
	pushdn(k);
	return (P[k<<1|1].mn<=m)?getrg(k<<1|1,mid+1,r):getrg(k<<1,l,mid);
}
void build(int k,int l,int r){
	if (l==r){
		P[k].num=s2[l]; P[k].mx=-s2[l]; return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	maintain(k,l,r);
}
int main(){
	scanf("%d%d",&n,&m);
	int i,j,k;
	for (i=1; i<n; i++) scanf("%d",&a[i]);
	for (i=1; i<=n; i++) scanf("%d",&b[i]);
	for (i=1; i<=n; i++){
		s1[i]=s1[i-1]+a[i-1]-b[i-1];
		s2[i]=s2[i-1]+a[i-1]-b[i];
	}
	build(1,1,n);
	for (i=n,j=0; i; i--){
		for (; j && s1[i]>=s1[q[j]]; j--) if (j>1)
			ins(1,1,n,q[j-1]-1,s1[q[j]]-s1[q[j-1]]);
		if (j) ins(1,1,n,q[j]-1,s1[q[j]]-s1[i]);
		q[++j]=i;
		if (i<n){
			k=min(getrg(1,1,n)+1,n);
			if (i<=k){
				tmp=0; qry(1,1,n,i,k,-inf); ans=max(ans,tmp-i+1);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}