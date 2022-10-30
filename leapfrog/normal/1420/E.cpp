//Coded by Kamiyama_Shiki on 2021.11.03 {{{
//
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
int n,a[85],id[85],idt,dp[85][85][3615];
inline void add(int &a,int w) {a=max(a,w);}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),(a[i]?id[++idt]=i:0);
	memset(dp,~0x3f,sizeof(dp)),dp[0][0][0]=0;int ln=n*(n-1)/2;
	for(int i=0,lm=min(i,idt-1);i<n;i++,lm=min(i,idt-1))
		for(int j=0;j<=lm;j++) for(int k=0;k<=ln;k++) if(dp[i][j][k]>=0)
			for(int w=i+1;w<=n;w++) add(dp[w][j+1][k+abs(w-id[j+1])],dp[i][j][k]+(i-j)*(w-i-1));
	int rs=0;for(int i=0;i<=ln;printf("%d%c",rs,i==ln?'\n':' '),i++) for(int j=1;j<=n;j++) add(rs,dp[j][idt][i]+(j-idt)*(n-j));
	return 0;
}