#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,k,x[1005],s[5][5],y[1005],tot=0;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
	while(true)
	{
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++)s[x[i]&1][y[i]&1]++;
		if(s[1][1]+s[0][0]>0&&s[1][0]+s[0][1]>0)
		{
			printf("%d\n",s[1][1]+s[0][0]);
			for(int i=1;i<=n;i++)if((x[i]&1)^(y[i]&1)==0)printf("%d ",i);return 0;
		}
		if(s[1][0]+s[0][0]>0&&s[1][1]+s[0][1]>0)
		{
			printf("%d\n",s[1][0]+s[0][0]);
			for(int i=1;i<=n;i++)if((y[i]&1)==0)printf("%d ",i);return 0;
		}
		else 
		{
			for(int i=1;i<=n;i++)x[i]=x[i]>>1,y[i]=y[i]>>1;
		}
	}
	return 0;
}