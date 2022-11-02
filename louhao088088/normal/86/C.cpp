// Problem: CF86C Genetic engineering
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF86C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-03-30 20:12:48
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=1e3+5,M=34005,mod=1e9+9;
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
int n,m,f[1005][205][15],ans=0;
int ch[maxn][4],fail[maxn],tot=0,cnt[maxn];
char a[maxn];queue<int>q;
void ins(int len)
{
	int now=0,x;
	for(int i=1;i<=len;i++)
	{
		if(a[i]=='A')x=0;
		if(a[i]=='C')x=1;
		if(a[i]=='T')x=2;
		if(a[i]=='G')x=3;
		if(!ch[now][x])ch[now][x]=++tot;
		now=ch[now][x];
	}cnt[now]=max(cnt[now],len);
}
void getfail()
{
	for(int i=0;i<4;i++)
		if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int v=ch[x][i];
			if(v)fail[v]=ch[fail[x]][i],cnt[v]=max(cnt[v],cnt[fail[v]]),q.push(v);
			else ch[x][i]=ch[fail[x]][i];
		}	
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)scanf("%s",a+1),ins(strlen(a+1));
	getfail();f[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=tot;j++)
			for(int l=0;l<10;l++)
			{
				if(!f[i-1][j][l])continue;
				for(int k=0;k<4;k++)
				{
					int t=ch[j][k];
					if(cnt[t]>l)f[i][t][0]=(f[i][t][0]+f[i-1][j][l])%mod;
					else f[i][t][l+1]=(f[i][t][l+1]+f[i-1][j][l])%mod;
				}	
			}
	for(int i=0;i<=tot;i++)
		ans+=f[n][i][0],ans%=mod;
	cout<<ans;
 	return 0;
}