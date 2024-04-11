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
int T,n;char c[205][205];
int main()
{
	for(read(T);T--;)
	{
		read(n);int A=0,B=0;
		for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
		A+=c[1][2]=='0',A+=c[2][1]=='0',A+=c[n-1][n]=='1',A+=c[n][n-1]=='1';
		B+=c[1][2]=='1',B+=c[2][1]=='1',B+=c[n-1][n]=='0',B+=c[n][n-1]=='0';
		if(A>B)
		{
			printf("%d\n",B);
			if(c[1][2]=='1') printf("1 2\n");
			if(c[2][1]=='1') printf("2 1\n");
			if(c[n-1][n]=='0') printf("%d %d\n",n-1,n);
			if(c[n][n-1]=='0') printf("%d %d\n",n,n-1);
		}
		else
		{
			printf("%d\n",A);
			if(c[1][2]=='0') printf("1 2\n");
			if(c[2][1]=='0') printf("2 1\n");
			if(c[n-1][n]=='1') printf("%d %d\n",n-1,n);
			if(c[n][n-1]=='1') printf("%d %d\n",n,n-1);
		}
	}
	return 0;
}