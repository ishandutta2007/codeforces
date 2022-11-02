#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int maxn=1e6+5,M=34005;
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
int n,m,q,sum[maxn],x,y;
string a[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();memset(sum,0x3f,sizeof sum);
	auto a=vector<vector<char>>(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar();
			while(a[i][j]!='.'&&a[i][j]!='X')
				a[i][j]=getchar();
		}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
			if(a[i-1][j]=='X'&&a[i][j-1]=='X')sum[j]=j;
	for(int j=m;j>=1;j--)
		sum[j]=min(sum[j],sum[j+1]);
	q=read();
	for(int i=1;i<=q;i++)
	{
		x=read(),y=read();
		if(sum[x+1]>y)puts("YES");
		else puts("NO");	
	}
 	return 0;
}