//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int m,n,a[(1<<20)+5],b[(1<<20)+5],T;ll cn[25][2];
inline void msort(int l,int r,int dep)
{
	int md,w,i,j;if(l==r) return;else msort(l,md=(l+r)>>1,dep-1),msort(md+1,r,dep-1);
	i=l,j=md+1;while(i<=md&&j<=r) if(a[i]<a[j]) cn[dep][1]+=r-j+1,i++;else j++;
	i=l,j=md+1;while(i<=md&&j<=r) if(a[i]>a[j]) cn[dep][0]+=md-i+1,j++;else i++;
	w=i=l,j=md+1;while(i<=md&&j<=r) if(a[i]>a[j]) b[w++]=a[j++];else b[w++]=a[i++];
	if(i<=md) while(i<=md) b[w++]=a[i++];else while(j<=r) b[w++]=a[j++];
	for(int i=l;i<=r;i++) a[i]=b[i];
}
int main()
{
	read(m),n=1<<m;for(int i=1;i<=n;i++) read(a[i]);
	msort(1,n,m);
	for(read(T);T--;)
	{
		int x;read(x);ll res=0;
		for(int i=1;i<=m;res+=cn[i][0],i++) if(i<=x) swap(cn[i][0],cn[i][1]);
		printf("%lld\n",res);
	}
	return 0;
}