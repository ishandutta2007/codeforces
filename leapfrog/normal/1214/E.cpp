//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,a[100005],id[200005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),id[i]=i<<1;
	sort(id+1,id+n+1,[](int x,int y){return a[x>>1]>a[y>>1];});
	for(int i=2;i<=n;i++) printf("%d %d\n",id[i-1],id[i]);
	int nw=n;for(int i=1;i<=n;i++)
	{
		int p=a[id[i]>>1];
		if(i+p-1<=nw)
		{
			printf("%d %d\n",id[i+p-1],id[i]-1);
			if(i+p-1==nw) id[++nw]=id[i]-1;
		}else assert(0);
		//else printf("%d %d\n",id[i+p-2]<<1,(id[i]<<1)-1),a[i+p-1]=(id[i]<<1)-1;
	}
	return 0;
}