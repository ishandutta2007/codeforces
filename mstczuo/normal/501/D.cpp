#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int f[1000010],a[300010],b[300010],p[300010],q[300010],n;
int ins(int ro,int l,int r,int tar){
	if (l==r) {
		f[ro]++;return f[ro]-1;
	}
	f[ro]++;
	int mid=(l+r)>>1;
	if (mid>=tar) return ins(ro<<1,l,mid,tar);
	else return f[ro<<1]+ins(ro<<1|1,mid+1,r,tar);
}
void build(int ro,int l,int r){
	if (l==r) {
		f[ro]++;return;
	}
	int mid=(l+r)>>1;
	build(ro<<1,l,mid);
	build(ro<<1|1,mid+1,r);
	f[ro]=f[ro<<1]+f[ro<<1|1];
}
int getkth(int ro,int l,int r,int tar){
	if (l==r) {
		f[ro]--;
		return l;	
	}
	f[ro]--;
	int mid=(l+r)>>1;
	if (f[ro<<1]>=tar) return getkth(ro<<1,l,mid,tar);
	return getkth(ro<<1|1,mid+1,r,tar-f[ro<<1]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&q[i]);
	memset(f,0,sizeof(f));
	for (int i=n;i>=1;i--) a[i]=ins(1,0,n-1,p[i]);
	memset(f,0,sizeof(f));
	for (int i=n;i>=1;i--) b[i]=ins(1,0,n-1,q[i]);
	for (int i=1;i<=n;i++) a[i]+=b[i];
	for (int i=n;i>=1;i--) a[i-1]+=a[i]/(n-i+1),a[i]%=n-i+1;
	memset(f,0,sizeof(f));
	build(1,0,n-1);
	int x;
	for (int i=1;i<=n;i++) {
		x=getkth(1,0,n-1,a[i]+1);
		printf("%d ",x);
	}
	printf("\n"); 
}