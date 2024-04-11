#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,v[maxn],b[maxn],sum[maxn],num=0,ans;
priority_queue<int,vector<int>,greater<int> > q;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read(),sum[i]=sum[i-1]+b[i];ans=0;
		q.push(v[i]+sum[i-1]);num++;
		while(!q.empty()&&q.top()<=sum[i])
		{
			ans+=q.top()-sum[i-1];q.pop();num--;
		}
		printf("%lld ",ans+num*b[i]);
	}
 	return 0;
}