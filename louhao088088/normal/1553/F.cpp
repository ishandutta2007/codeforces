#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
#define lowbit(i) (i&(-i))
const int maxn=3e5+5;
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
int a[maxn],n,c[maxn*2],p[maxn],Max,c2[maxn*2],sum;
void add(int x,int num){for(int i=x;i<=Max;i+=lowbit(i))c[i]+=num;}
int qry(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=c[i];return res;}
void add2(int x,int num){for(int i=x;i<=Max;i+=lowbit(i))c2[i]+=num;}
int qry2(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=c2[i];return res;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
  	n=read();
  	for(int i=1;i<=n;i++)a[i]=read(),Max=max(Max,a[i]*2);//cout<<Max<<endl;
    for(int i=1;i<=n;i++)
	{
       	p[i]=p[i-1]+a[i]*(i-1)+sum;p[i]-=qry(a[i]);
        for(int j=a[i];j+a[i]<=Max;j+=a[i])p[i]-=(qry2(j+a[i]-1)-qry2(j-1))*j,add(j,a[i]);
        add2(a[i],1);print(p[i]),putchar(' ');sum+=a[i];
    }
 	return 0;
}