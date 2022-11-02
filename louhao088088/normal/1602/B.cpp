#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int maxn=2e3+5,M=34005;
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
int a[maxn][maxn],n,m,T,sum[maxn],q,x,y;
map<int,int>p;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		p.clear();n=read();
		//cout<<"A"<<n<<endl;
		for(int i=1;i<=n;i++)
			a[i][0]=read(),p[a[i][0]]++;
		for(int i=1;i<=n;i++)
			a[i][1]=p[a[i][0]];
		for(int j=2;j<=n;j++)
		{
			for(int i=1;i<=n;i++)sum[i]=0;
			for(int i=1;i<=n;i++)
				sum[a[i][j-1]]++;
			for(int i=1;i<=n;i++)
				a[i][j]=sum[a[i][j-1]];
		}
		q=read();
		for(int i=1;i<=q;i++)
		{
			x=read(),y=read();y=min(y,n);
			printf("%d\n",a[x][y]);
		}
	}
 	return 0;
}