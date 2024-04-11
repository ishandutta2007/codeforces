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
const int N=405;int n,m,a[N][N],L[N][N],ls[N][N],tn[N*N];
inline void ckmx(int &a,int b) {a>b?a:a=b;}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	int rs=0;for(int up=n;up>=1;up--)
	{
		for(int l=1;l<=m;l++)
			ls[up][l]=max(ls[up][l-1],tn[a[up][l]]+1),
			tn[a[up][l]]=l,rs=max(rs,l-ls[up][l]+1);
		for(int l=1;l<=m;l++) tn[a[up][l]]=0;
		for(int dw=up+1;dw<=n;dw++)
		{
			for(int l=1;l<=m;l++)
			{
				ls[dw][l]=a[up][l]^a[dw][l]?max(ls[dw][l],max(tn[a[up][l]],tn[a[dw][l]])+1):l+1;
				ckmx(ls[dw][l],max(ls[dw-1][l],ls[dw][l-1])),tn[a[up][l]]=tn[a[dw][l]]=l;
				rs=max(rs,(dw-up+1)*(l-ls[dw][l]+1));
			}
			for(int l=1;l<=m;l++) tn[a[up][l]]=tn[a[dw][l]]=0;
		}
	}
	return printf("%d\n",rs),0;
}