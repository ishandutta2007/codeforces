#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
#define mp make_pair
#define fi first
#define se second
const int maxn=1e5+5,M=(1<<18);
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
int n,m,k,f[19][M],x,y,z,a[maxn],ans,b[19][19];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=k;i++)x=read(),y=read(),z=read(),b[x][y]=z;
	int h=1<<n;
	for(int i=1;i<h;i++)
	{
		int g=0;
		for(int j=1;j<=n;j++)
			if(i&(1<<(j-1)))
			{
				int sum=0;
				for(int l=1;l<=n;l++)
					if(i&(1<<(l-1)))sum=max(b[l][j]+f[l][i^(1<<(j-1))],sum);
				f[j][i]=a[j]+sum;//cout<<j<<" "<<i<<" "<<f[j][i]<<" "<<sum<<endl;
				g++;
			}
		if(g==m)
		{
			for(int j=1;j<=n;j++)
				if(i&(1<<(j-1)))
					ans=max(ans,f[j][i]);
		}
	}
	cout<<ans;
 	return 0;
}