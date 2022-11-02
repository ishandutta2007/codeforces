#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mid (l+r>>1)
#define int long long
const int maxn=3e3+5,M=34005;
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
int n,m,ans,x,sum[maxn],b[maxn],f[maxn];
vector<int>a[maxn];
void add(int x)
{
	for(int i=m;i>=b[x];i--)f[i]=max(f[i],f[i-b[x]]+sum[x]);
}
void solve(int l,int r)
{
	if(l==r)
	{
		ans=max(ans,f[m]);
		for(int i=0;i<b[l]&&m-i-1>=0;i++)ans=max(ans,f[m-i-1]+a[l][i]);
		//cout<<ans<<" "<<l<<" "<<f[2]<<endl;
		return;
	}
	vector<int>tmp;tmp.resize(m+5);
	for(int i=1;i<=m;i++)tmp[i]=f[i];
	for(int i=l;i<=mid;i++)add(i);solve(mid+1,r);
	for(int i=1;i<=m;i++)f[i]=tmp[i];
	for(int i=mid+1;i<=r;i++)add(i);solve(l,mid);
	for(int i=1;i<=m;i++)f[i]=tmp[i];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();sum[i]=0;a[i].resize(b[i]);
		for(int j=0;j<b[i];j++)
			x=read(),sum[i]+=x,a[i][j]=sum[i];
	}
	solve(1,n);
	cout<<ans<<endl;
 	return 0;
}