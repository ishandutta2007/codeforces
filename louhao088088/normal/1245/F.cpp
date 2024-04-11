#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define int long long
const int maxn=1e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int l,r,dp[105][3][3],a[105],b[105],lenl,lenr,ans,T;
int dfs(int pos,int x1,int x2)
{
	if(pos==0)return 1;
	if(dp[pos][x1][x2]!=-1)return dp[pos][x1][x2];
	int res=0;
	int t1=x1?a[pos]:1,t2=x2?b[pos]:1;
	for(int i=0;i<=t1;i++)
		for(int j=0;j<=min(1-i,t2);j++)
			res+=dfs(pos-1,x1&(i==a[pos]),x2&(j==b[pos]));
	//cout<<pos<<" "<<x1<<" "<<x2<<" "<<res<<endl;
	dp[pos][x1][x2]=res;
	return res;
}
int getans(int l,int r)
{
	if(l<0||r<0)return 0;
	memset(dp,-1,sizeof dp);memset(a,0,sizeof a);memset(b,0,sizeof b);lenl=0,lenr=0;
	while(l){a[++lenl]=l&1;l=l>>1;}
	while(r){b[++lenr]=r&1;r=r>>1;}
	//cout<<lenr<<endl;
	return dfs(lenr,1,1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		l=read(),r=read();
		cout<<getans(r,r)+getans(l-1,l-1)-2*getans(l-1,r)<<endl;
	}
 	return 0;
}