#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=2e5+5;
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
int n,m,x,y,a[maxn],b[maxn],T,ans,flag[maxn],k,tot;
void solve()
{
	n=read(),k=read();tot=0;
	if(n==4&&k==3){cout<<"-1"<<endl;return;}
	for(int i=0;i<n;i++)flag[i]=0;
	for(int i=0;i<n/2;i++)
	{
		a[++tot]=i,b[tot]=n-i-1;
		if(i==k)a[tot]=0;
		if(n-i-1==k)b[tot]=0;
	}a[1]=k;
	if(n-1!=k)
	{
		for(int i=1;i<=tot;i++)printf("%d %d\n",a[i],b[i]);
	}
	else
	{
		tot=0;
		for(int i=0;i<n/2;i++)
		{
			a[++tot]=i,b[tot]=n-i-1;
		}a[1]=k-1;
		b[2]=3;a[4]=0;
		
		for(int i=1;i<=tot;i++)printf("%d %d\n",a[i],b[i]);
	}
	int sum=0;
//	for(int i=1;i<=tot;i++)sum+=a[i]&b[i];
//		cout<<sum<<endl;
} 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)solve();
 	return 0;
}