//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,m;char ch[505][505],fg[505][505];
int main()
{
	read(n,m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ch[i][j]=ch[i][j]=='B';
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fg[i][j]=ch[i][j]^ch[i][j+1]^ch[i+1][j]^ch[i+1][j+1];
	int rs=0;for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) rs+=fg[i][j];
	if(fg[n][m]) for(int i=1;i<n;i++) for(int j=1;j<m;j++)
		if(fg[i][j]&&fg[i][m]&&fg[n][j]) return printf("%d\n",rs-1),0;
	return printf("%d\n",rs),0;
}