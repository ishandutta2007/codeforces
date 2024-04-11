#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,q,a[333333],num[300011],qzh[300011],x[333333],y[333333],k[333333],mn;
int v[333333],cnt,px;
int ans[333333],p[333333],kp[2222],pnt;
bool f;
inline void scan(int &ret)
{
	char c;ret=0;
	while((c=getchar())<'0' || c>'9');
	while(c>='0'&&c<='9')
	{
		ret=ret*10+(c-'0');
		c=getchar();
	}
} 
inline void out(int x)
{
	if(x>9) out(x/10);
	putchar(x%10+'0'); 
}
int main()
{
	scan(n);
	scan(q);
	for (int i=1;i<=n;i++)
	{
		scan(a[i]);
		num[a[i]]++;
	}
	for (int i=1;i<=q;i++)
	{
		scan(x[i]);
		scan(y[i]);
		scan(k[i]);
		p[i]=(y[i]-x[i]+1)/k[i];
	}
	px=300;
	for (int i=1;i<=n;i++)
	{
		if (num[i]>px) v[cnt++]=i; 
	}
	for (int i=0;i<cnt;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[j]==v[i]) qzh[j]=qzh[j-1]+1;
			else qzh[j]=qzh[j-1];
		}
		for (int j=1;j<=q;j++)
		{
			if (ans[j]) continue;
			if (y[j]-x[j]>px*k[j]) 
			{
				if (qzh[y[j]]-qzh[x[j]-1]>p[j]) ans[j]=v[i];
			}
		}
	}
	memset(num,0,sizeof(num));
	for (int i=1;i<=q;i++)
	{
		if (y[i]-x[i]<=px*k[i])
		{
			for (int j=1;j<=pnt;j++) num[kp[j]]=0;
			mn=1e9;
			pnt=0;
			for (int j=x[i];j<=y[i];j++)
			{
				kp[++pnt]=a[j];
				num[a[j]]++;
				if (a[j]<mn && num[a[j]]>p[i]) mn=a[j];
			}
			if (mn==1e9) puts("-1");
			else 
			{
				out(mn);
				putchar('\n');
			}
		}
		else
		{
			if (!ans[i]) puts("-1");
			else 
			{
				out(ans[i]);
				putchar('\n');
			}
		}
	}
	return 0;
}