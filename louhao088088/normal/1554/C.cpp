#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
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
int T,n,a[45],ans,k,m;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();a[0]=1;
	for(int i=1;i<=32;i++)a[i]=a[i-1]*2;//cout<<a[32]<<endl;
	while(T--)
	{
		n=read();m=read();int t=0,g=n;
		if(n>m){puts("0");continue;}
		while(n>=a[t])t++;
		k=m/a[t];m=m%a[t];//cout<<n<<" "<<m<<" "<<a[t]<<endl;
		if(n>m){print(a[t]*k);puts("");continue;}
		else
		{
			int x=n,s=0;
			for(int i=0;i<=31;i++)
			{
				x=n;if(n>m)break;
				for(int j=0;j<=31;j++)
				{
					if(!(x&a[j]))
					{
						x+=a[j];
						if(x>m){n+=a[j];s+=a[j];break;}
					}
				}
			}
			if(n==m) print(m+1+a[t]*k);
			else
			print(s+a[t]*k);puts("");
		}
	}
 	return 0;
}