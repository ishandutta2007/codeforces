#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=2000010;
int n,a[MAXN],b[MAXN],c[MAXN],Q,x;
LL inv1[100],inv2[100];
void MergeSort(int l,int r,int h,LL inv[])
{
	if(h==0) return;
	int mid=(l+r)>>1;
	MergeSort(l,mid,h-1,inv);
	MergeSort(mid,r,h-1,inv);
	int t1=l,t2=mid,t3=l;
	for(int i=l;i<r;i++) b[i]=a[i];
	while(t1<mid&&t2<r)
	{
		if(b[t1]<=b[t2]) a[t3++]=b[t1++],inv[h]+=(LL)(t2-mid);
		else a[t3++]=b[t2++];
	}
	while(t1<mid) a[t3++]=b[t1++],inv[h]+=(LL)(t2-mid);
	while(t2<mid) a[t3++]=b[t2++];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++) scanf("%d",&a[i]),c[i]=a[i];
	MergeSort(0,(1<<n),n,inv1);
	for(int i=0;i<(1<<n);i++) a[i]=c[i];
	reverse(a,a+(1<<n));
	MergeSort(0,(1<<n),n,inv2);
	scanf("%d",&Q);
	for(int T=1;T<=Q;T++)
	{
		LL ans=0;
		scanf("%d",&x);
		for(int i=1;i<=x;i++) swap(inv1[i],inv2[i]);
		for(int i=1;i<=n;i++) ans+=inv1[i];
		printf("%I64d\n",ans);
	}
	return 0;
}