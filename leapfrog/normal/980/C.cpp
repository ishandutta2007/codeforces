//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,k,c[305];
int main()
{
	read(n),read(k),memset(c,-1,sizeof(c));
	for(int i=1,x;i<=n;i++)
	{
		read(x);if(~c[x]) {printf("%d ",c[x]);continue;}
		int qwq=x;while(qwq>=0&&qwq>x-k&&!~c[qwq]) qwq--;
		int mx=qwq+1;if(qwq>=0&&x-c[qwq]<k) mx=min(mx,c[qwq]);
		printf("%d ",mx);for(int j=qwq+1;j<=x;j++) c[j]=mx;
		// printf("x : %d , qwq : %d\n",x,qwq);
		// for(int j=0;j<20;j++) printf("%d",c[j]);putchar('\n');
	}
	return putchar('\n'),0;
}