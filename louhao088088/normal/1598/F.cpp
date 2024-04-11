#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int maxn=4e5+5,M=34005;
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
int n,m,a[maxn],sum[25][maxn*2],tot,Min[maxn],num,len,f[1<<20],ans=0;
char s[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	n=read();
 	for(int i=1;i<=n;i++)
	{
	 	scanf("%s",s+1);num=0;len=strlen(s+1);
	 	for(int j=1;j<=len;j++)
	 	{
	 		if(s[j]=='(')num++;
	 		else num--;Min[i]=min(num,Min[i]);
	 		if(num==Min[i])sum[i][num+maxn]++;
		}a[i]=num;
	}
	memset(f,0x80,sizeof f);f[0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		tot=0;
		for(int j=1;j<=n;j++)
			if((1<<(j-1))&i)tot+=a[j];
		for(int j=1;j<=n;j++)
			if(!((1<<(j-1)&i)))
			{
				ans=max(ans,sum[j][-tot+maxn]+f[i]);
			//	cout<<tot<<" "<<i<<" "<<sum[j][-tot+maxn]<<" "<<Min[j]<<endl;
				if(tot+Min[j]>=0)f[i|(1<<(j-1))]=max(f[i|(1<<(j-1))],f[i]+sum[j][-tot+maxn]);
			}
	}
	cout<<ans;
	return 0;
}