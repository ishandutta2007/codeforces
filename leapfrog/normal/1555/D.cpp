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
const int N=200005;
int n,q,s[N][3],t[N][3];char ch[N];
inline void chkmx(int &x,int w) {x=min(x,w);}
int main()
{
	read(n,q),scanf("%s",ch+1);
	for(int i=1;i<=n;i++) ch[i]-='a';
	for(int i=1;i<=n;i++) for(int j=0;j<3;j++) s[i][j]=s[i-1][j]+(ch[i]!=(j+i)%3);
	for(int i=1;i<=n;i++) for(int j=0;j<3;j++) t[i][j]=t[i-1][j]+(ch[i]!=(j+i*2)%3);
	for(int l,r;q--;)
	{
		read(l,r);int rs=r-l+1;
		for(int i=0;i<3;i++) chkmx(rs,s[r][i]-s[l-1][i]);
		for(int i=0;i<3;i++) chkmx(rs,t[r][i]-t[l-1][i]);
		printf("%d\n",rs);
	}
	return 0;
}