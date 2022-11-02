//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,m,a[2000005],wh[55],tn[55],at;char v[55];
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]),wh[a[i]]?0:wh[a[i]]=i;
	for(int t;m--;wh[t]=1)
	{
		read(t),printf("%d ",wh[t]);
		for(int i=1;i<=50;i++) if(wh[i]<wh[t]) wh[i]++;
	}
	return putchar('\n'),0;
}