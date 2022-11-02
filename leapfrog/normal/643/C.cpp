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
const int N=200005;int n,K,t[N],qr[N],hd,tl;
double s[N],sm[N],q[N],dp[51][N];int nwk;
inline double X(int a) {return s[a];}
inline double Y(int a) {return dp[nwk-1][a]-sm[a]+s[a]*q[a];}
inline double slop(int x,int y) {return(Y(y)-Y(x))/(X(y)-X(x));}
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(t[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+t[i],sm[i]=sm[i-1]+s[i]/t[i],q[i]=q[i-1]+1.0/t[i];
	for(int i=1;i<=n;i++) dp[0][i]=sm[i];
	for(int k=1;k<K;k++)
	{
		qr[hd=tl=1]=0,nwk=k;for(int i=1;i<=n;i++)
		{
			while(hd<tl&&slop(qr[hd],qr[hd+1])<q[i]) hd++;
			int j=qr[hd];dp[k][i]=dp[k-1][j]-sm[j]+s[j]*q[j]-s[j]*q[i]+sm[i];
			//printf("%d -> %d\n",j,i);
			while(hd<tl&&slop(qr[tl],i)<=slop(qr[tl-1],qr[tl])) tl--;
			qr[++tl]=i;
		}
		//for(int i=1;i<=n;i++) printf("%.5lf%c",dp[k][i],i==n?'\n':' ');
	}
	return printf("%.10lf\n",dp[K-1][n]),0;
}