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
const int maxn=1e5+5,M=34005;
#define int long long
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
int n,m,t,ans,x,y,g=0,f[maxn];
char a[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	scanf("%s",a+1);m=strlen(a+1);memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=1;i<=m;i++)
	{
		if(f[i-1]>f[m+1]/n)continue;
		if(a[i]=='0')f[i]=min(f[i],f[i-1]*n);
		else 
		{
			x=0;
			for(int j=i;j<=m;j++)
			{
				x=x*10+a[j]-'0';
				if(x>=n)break;
				f[j]=min(f[j],f[i-1]*n+x);
			}
		}
	}
	cout<<f[m];
 	return 0;
}