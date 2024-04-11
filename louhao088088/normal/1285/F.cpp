#include<bits/stdc++.h>
using namespace std;
#define int long long
static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,a[maxn],mu[maxn],f[maxn],p[maxn],cnt=0,s[maxn],Max=0,sum[maxn],st[maxn],top,ans=0;
vector<int>b,d[maxn];
void init(int n)
{
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1,p[++cnt]=i,mu[i]=-1;	
		}
		for(int j=1;j<=cnt&&p[j]*i<=n;j++)
		{
			f[p[j]*i]=1;if(i%p[j]==0)break; 
			else mu[p[j]*i]=-mu[i];
		}		
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			d[j].push_back(i);
}
signed main()
{
	n=read();init(100000);
	for(int i=1;i<=n;i++)a[i]=read(),s[a[i]]++,Max=max(Max,a[i]);
	for(int i=1;i<=Max;i++)
	{
		b.clear();
		for(int j=i;j<=Max;j+=i)
			for(int k=1;k<=s[j];k++)b.push_back(j/i);
		for(int j=b.size()-1;j>=0;j--)
		{
			int t=0,x,y;x=b[j];
			for(int k=0;k<d[x].size();k++)t+=mu[d[x][k]]*sum[d[x][k]],sum[d[x][k]]++;
			//if(i==1)cout<<x<<" "<<j<<" "<<t<<" "<<top<<endl;
			while(t&&top)
			{
				y=b[st[top]];top--;for(int k=0;k<d[y].size();k++)sum[d[y][k]]--;
				//if(x==23&&i==1)cout<<b[y]<<" "<<top<<endl;
				if(__gcd(x,y)==1)t--,ans=max(ans,x*y*i);
			}
			top++;st[top]=j;
		}
		while(top)
		{
			int y=st[top];top--;
			for(int k=0;k<d[y].size();k++)sum[d[y][k]]--;
		}	
	}
	cout<<ans;
	return 0;
}