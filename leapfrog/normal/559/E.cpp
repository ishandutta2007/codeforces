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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=105;int n,rs,F[N][N][2];pair<int,int>a[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].first,a[i].second);
	sort(a+1,a+n+1),a[0].first=-1e9;for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++) for(int k=0;k<2;k++)
		{
			rs=max(rs,F[i][j][k]);int l=a[j].first+k*a[j].second,mx=-1e9,wx,wy;
			for(int z=i+1;z<=n;z++) for(int w=0;w<2;w++)
			{
				int L=a[z].first+w*a[z].second;
				if(L>mx) mx=L,wx=z,wy=w;
				F[z][wx][wy]=max(F[z][wx][wy],F[i][j][k]+min(a[z].second,L-l)+mx-L);
			}
		}
	return printf("%d\n",rs),0;
}