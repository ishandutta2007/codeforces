//Coded by Kamiyama_Shiki on 2021.11.14 {{{
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
const int N=3005,P=1000000007;
namespace SAM
{
	struct sam{int fa,len,ch[2];}S[N<<1];int smt=1,sls=1;
	inline void saminit() {smt=sls=1;}
	inline void samins(int c)
	{
		int p=sls,np=sls=++smt;S[np].len=S[p].len+1;
		for(;p&&!S[p].ch[c];p=S[p].fa) S[p].ch[c]=np;
		int q=S[p].ch[c];if(!q) return S[np].fa=1,void();
		if(S[p].len+1==S[q].len) return S[np].fa=q,void();
		int nq=++smt;S[nq]=S[q],S[nq].len=S[p].len+1,S[q].fa=S[np].fa=nq;
		for(;p&&S[p].ch[c]==q;p=S[p].fa) S[p].ch[c]=nq;
	}
}using namespace SAM;
int Q,dp[N][N],rs=0,ch[N];
inline char chk(int r)
{
	int vl=ch[r-3]<<3|ch[r-2]<<2|ch[r-1]<<1|ch[r];
	return vl!=3&&vl!=5&&vl!=14&&vl!=15;
}
int main()
{
	dp[1][0]=0,saminit(),read(Q),dp[1][0]=1;
	for(int n=1;n<=Q;n++)
	{
		int x;read(x),ch[n]=x,samins(x),dp[n+1][n]=1;
		for(int l=1;l<=n;l++)
		{
			if(n-1>=0) dp[l][n]=(dp[l][n]+dp[l][n-1])%P;else continue;
			if(n-2>=0) dp[l][n]=(dp[l][n]+dp[l][n-2])%P;else continue;
			if(n-3>=0) dp[l][n]=(dp[l][n]+dp[l][n-3])%P;else continue;
			if(n-4>=0&&chk(n)) dp[l][n]=(dp[l][n]+dp[l][n-4])%P;else continue;
		}
		int ls=n-S[S[sls].fa].len;
		for(int i=1;i<=ls;i++) rs=(rs+dp[i][n])%P;
		printf("%d\n",rs);
	}return 0;
}