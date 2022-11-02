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
int a,b,x,y,n,m,t,z,len=0,sum[maxn][3],tot=0;
void exgcd(int a,int b)
{
	if(b==0){x=1,y=0;return;}
	exgcd(b,a%b);
	int z=x;
	x=y;
	y=z-(a/b)*y;
}
int mul(int x,int y)
{
	int res=0;
	while(y)
	{
		if(y&1)
		{
			sum[++tot][0]=1;sum[tot][1]=x,sum[tot][2]=res;res+=x;
		}
		sum[++tot][0]=1;sum[tot][1]=x,sum[tot][2]=x;x+=x;y=y/2;
	}
	return res;
}
signed main()
{
	n=read();m=n;
	sum[++tot][0]=0;sum[tot][1]=m,sum[tot][2]=m;
	while(m)
	{
		m=m/2;len++;
	}m=n;len--;
	while(len)
	{
		sum[++tot][0]=1;sum[tot][1]=m,sum[tot][2]=m;len--;
		m+=m;
	}
	sum[++tot][0]=0;sum[tot][1]=m,sum[tot][2]=n;
	a=m^n;b=n;
	exgcd(a,b);
	int g=(x%b+b)%b;
	int k=g*a/n;
	m=mul(n,k);g=mul(a,g);
	//cout<<"A"<<" "<<g<<" "<<a<<" "<<b<<endl;
	if(m%2==0)sum[++tot][0]=0,sum[tot][1]=m,sum[tot][2]=g;
	else 
	{
		sum[++tot][0]=1;sum[tot][1]=m,sum[tot][2]=m;
		sum[++tot][0]=1;sum[tot][1]=m,sum[tot][2]=g;
		sum[++tot][0]=0;sum[tot][1]=m*2,sum[tot][2]=m+g;
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)
	{
		if(sum[i][0])
		{
			printf("%lld + %lld\n",sum[i][1],sum[i][2]);
		}
		else
		{
			printf("%lld ^ %lld\n",sum[i][1],sum[i][2]);
		}
	}
	return 0;
}