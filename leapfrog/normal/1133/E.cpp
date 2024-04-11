#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,k,a[5005],v[5005],d[5005][5005],qz[5005][5005];
int main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);int maxn=0;
	for(int r=n,l=n;r>=1;r--) {while(l>=1&&a[r]-a[l]<=5) l--;v[r]=l+1;}
	// for(int w=1;w<=k;w++)
	// {
	// 	d[w&1][1]=1,qz[w&1][1]=1;
	// 	for(int i=2;i<=n;i++)
	// 	{
	// 		d[w&1][i]=max(d[w][(i-1)&1],i-v[i]+1),d[w&1][i]=max(d[w&1][i],qz[(w-1)&1][v[i]-1]+i-v[i]+1),qz[w&1][i]=max(qz[w&1][i-1],d[w&1][i]);
	// 		for(int j=1;j<v[i];j++) d[w&1][i]=max(d[w&1][i],d[(w-1)&1][j]+i-v[i]+1);
	// 	}
	// }
	for(int w=1;w<=k;w++)
	{
		d[w][1]=1,qz[w][1]=1;
		for(int i=2;i<=n;i++)
		{
			d[w][i]=max(d[w][i-1],i-v[i]+1),d[w][i]=max(d[w][i],qz[w-1][v[i]-1]+i-v[i]+1),qz[w][i]=max(qz[w][i-1],d[w][i]);
			// for(int j=1;j<v[i];j++) d[w][i]=max(d[w][i],d[w-1][j]+i-v[i]+1);
			// if(s<=t) d[w][i]=max(d[w-1][q[s]-1]+i-q[s]+1,d[w][i]);
			// {while(s<=t&&q[t]<=d[w][i]) t--;}q[++t]=i;
			// printf("%d : ",i);
			// for(int j=s;j<=t;j++) printf("%d ",q[j]);
			// puts("");
		}
	}
	// for(int i=1;i<=n;i++) printf("%d%c",v[i],i==n?'\n':' ');
	// for(int w=1;w<=k;w++) for(int i=1;i<=n;i++) printf("%d%c",d[w][i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) maxn=max(maxn,d[k][i]);
	return printf("%d\n",maxn),0;
}