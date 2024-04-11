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
int n,m;char ch[1000005];int qz[1000005];
vector<char>v[1000005];vector<int>dp[1000005],sm[1000005];
int main()
{
	read(n,m);for(int i=0;i<=n;i++)	v[i].resize(m+1),dp[i].resize(m+1),sm[i].resize(m+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		for(int j=1;j<=m;j++) v[i][j]=ch[j];
	}
	for(int i=1;i<n;i++) for(int j=1;j<m;j++) sm[i][j]=(v[i][j+1]=='X'&&v[i+1][j]=='X');
	for(int i=1;i<n;i++) for(int j=1;j<m;j++) if(sm[i][j]) qz[j]=1;
	for(int i=1;i<m;i++) qz[i]+=qz[i-1];
	//for(int i=1;i<n;i++) for(int j=1;j<n;j++) sm[i][j]=sm[i][j]+sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1];
	int Q;read(Q);for(int i=1,x,y;i<=Q;i++)
	{
		read(x,y);if(x==y) {puts("YES");continue;}
		if(qz[y-1]-qz[x-1]) puts("NO");else puts("YES");
	}return 0;
}