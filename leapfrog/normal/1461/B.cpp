//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,m,s[505][505];char c[505][505];
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m);long long res=0;
		for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) c[i][j]=c[i][j]=='*';
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]=s[i][j-1]+c[i][j];
		for(int x=1;x<=n;x++) for(int y=1;y<=m;y++) if(c[x][y])
		{
			int i=1;
			while(1) if(x+i-1<=n&&y-i+1>=1&&y+i-1<=m&&s[x+i-1][y+i-1]-s[x+i-1][y-i]==i+i-1) i++;else break;
			res+=i-1;
		}
		printf("%lld\n",res);
	}
	return 0;
}