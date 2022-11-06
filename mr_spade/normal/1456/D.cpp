#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using std::max;
using std::min;
inline int abs(int x)
{
	return x<0?-x:x;
}
const int N=5005,inf=0x3f3f3f3f;
int n;
int t[N],x[N];
int f[N],g[N][2];
int lastp[N];
inline bool judge(int a,int b,int t)
{
	return abs(x[a]-x[b])<=t;
}
inline bool pass_by(int a,int b,int c,int t)
{
	return abs(x[a]-x[c])+abs(x[c]-x[b])<=t;
}
inline void init()
{
	register int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=i-2;j>=1;j--)
			if(pass_by(j,j+1,i,t[j+1]-t[j]))
			{
				lastp[i]=j;
				break;
			}
	}
}
inline bool spj(int i,int j)
{
	int tt=max(t[i]+abs(x[j]-x[i]),t[i+1]);
	return judge(j,i+2,t[i+2]-tt);
}
inline bool spj2(int i,int j)
{
	int tt=max(f[i]+abs(x[j]-x[i]),t[i]);
	return judge(j,i+1,t[i+1]-tt);
}
signed main()
{
	int tt;
	register int i,j;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&t[i],&x[i]);
	init();
	memset(f,0x3f,sizeof(f));
	f[0]=0;g[0][0]=1;
	for(i=0;i<n;i++)
	{
		if(f[i]<inf)
		{
			if(judge(i,i+1,t[i+1]-f[i]))
			{
				for(j=i+1;j<=n;j++)
				{
					g[j][0]=1;
					if(j<n&&(spj2(i,j+1)||lastp[j+1]>=i+1))
						g[j][1]=1;
					if(j<n&&!judge(j,j+1,t[j+1]-t[j]))
						break;
				}
			}
		}
		if(g[i][0])
		{
			tt=t[i];
			for(j=i+1;j<=n;j++)
			{
				if(!judge(j-1,j,t[j]-tt))
					break;
				tt=max(tt+abs(x[j]-x[j-1]),t[j-1]);
				f[j]=min(f[j],tt);
			}
		}
		if(g[i][1])
		{
			if(i+2<=n)
			{
				if(!judge(i,i+2,t[i+2]-t[i]))
					goto end1;
				tt=max(t[i]+abs(x[i+2]-x[i]),t[i+1]);
				f[i+2]=min(f[i+2],tt);
				for(j=i+3;j<=n;j++)
				{
					if(!judge(j-1,j,t[j]-tt))
						break;
					tt=max(tt+abs(x[j]-x[j-1]),t[j-1]);
					f[j]=min(f[j],tt);
				}
			}
			end1:;
			if(i+2<=n&&judge(i,i+2,t[i+2]-t[i]))
			{
				for(j=i+2;j<=n;j++)
				{
					g[j][0]=1;
					if(j<n&&(spj(i,j+1)||lastp[j+1]>=i+2))
						g[j][1]=1;
					if(j<n&&!judge(j,j+1,t[j+1]-t[j]))
						break;
				}
			}
		}
	}
	if(f[n]<inf||g[n][0]||g[n-1][1])
		puts("YES");
	else
		puts("NO");
	return 0;
}