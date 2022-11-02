#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=705,M=34005,mod=1e9+7;
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
int n,m,dp[maxn][maxn][3][3],len,st[maxn],tot=0,b[maxn],ans;
char s[maxn];
void dfs(int x,int y)
{
	//cout<<x<<" "<<y<<endl;
	if(x>y)return;
	if(x+1==y){dp[x][y][0][1]=dp[x][y][1][0]=dp[x][y][2][0]=dp[x][y][0][2]=1;}
	else if(b[x]==y)
	{
		//cout<<x<<" "<<b[x]<<" "<<y<<endl;
		dfs(x+1,y-1);
		for(int i=0;i<=2;i++)
			for(int j=0;j<=2;j++)
			{
				if(i!=1)dp[x][y][1][0]+=dp[x+1][y-1][i][j],dp[x][y][1][0]%=mod;
				if(i!=2)dp[x][y][2][0]+=dp[x+1][y-1][i][j],dp[x][y][2][0]%=mod;
				if(j!=1)dp[x][y][0][1]+=dp[x+1][y-1][i][j],dp[x][y][0][1]%=mod;
				if(j!=2)dp[x][y][0][2]+=dp[x+1][y-1][i][j],dp[x][y][0][2]%=mod;
			}		
	}
	else
	{
		dfs(x,b[x]),dfs(b[x]+1,y);
		for(int i=0;i<=2;i++)
			for(int j=0;j<=2;j++)
				for(int k=0;k<=2;k++)
					for(int l=0;l<=2;l++)
					{
						if(l==k&&k!=0)continue;
						dp[x][y][i][j]+=dp[x][b[x]][i][k]*dp[b[x]+1][y][l][j]%mod;
						dp[x][y][i][j]%=mod;
					}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",s+1);len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='(')st[++tot]=i;
		else b[st[tot]]=i,b[i]=st[tot],tot--;
	}
	dfs(1,len);
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			ans+=dp[1][len][i][j],ans%=mod;
	cout<<ans;
 	return 0;
}