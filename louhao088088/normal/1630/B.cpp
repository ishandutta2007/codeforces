#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=5e5+5;
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
#define lowbit(x) (x&(-x))
int n,m,x,y,a[maxn],b[maxn],T,ans,flag[maxn],k,tot,l,r,c[maxn];
void add(int x,int num){for(int i=x;i<=n;i+=lowbit(i))c[i]+=num;}
int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=c[i];return res;}
bool check(int x)
{
	for(int i=1;i+x<=n;i++)
		if(2*(query(i+x)-query(i-1))-n>=k)return 1;
	return 0;
}
void solve()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read(),add(a[i],1);
	l=0,r=n,ans=n-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	for(x=1;x;x++)	if(2*(query(x+ans)-query(x-1))-n>=k)break;y=x+ans;
	cout<<x<<" "<<y<<endl;
	int z=1,sum=0;
	for(int i=1,j=0;j+1<k;i++)
	{
		if(x<=a[i]&&a[i]<=y)sum++;else sum--;
		if(sum==j+1)
		{
			j++;printf("%lld %lld\n",z,i);z=i+1;
		}
	}
	cout<<z<<" "<<n<<endl;
	for(int i=1;i<=n;i++)add(a[i],-1);
} 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)solve();
 	return 0;
}