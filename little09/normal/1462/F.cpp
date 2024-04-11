#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,id,q,num;
}a[500005];
int L[500005],R[500005];
int ans[500005],res;
bool cmp(point x,point y)
{
	return x.x<y.x;
}
int cnt,n;
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int main()
{
	int T=read();
	while (T--)
	{
		cin >> n;
		cnt=0;
		for (int i=1;i<=n;i++)
		{
			int x=read(),y=read();
			ans[i]=0;
			a[++cnt].x=x,a[cnt].q=i,a[cnt].id=1;
			a[++cnt].x=y,a[cnt].q=i,a[cnt].id=2;
		}
		sort(a+1,a+cnt+1,cmp);
		int tot=0;
		for (int i=1;i<=cnt;i++)
		{
			if (i==1) a[i].num=++tot;
			else if (a[i].x!=a[i-1].x) a[i].num=++tot;
			else a[i].num=tot;
		}
		for (int i=0;i<=cnt+1;i++)
		{
			L[i]=0,R[i]=0;
		}
		for (int i=1;i<=cnt;i++)
		{
			if (a[i].id==1) L[a[i].num]++;
			else R[a[i].num]++;
		}
		for (int i=2;i<=cnt;i++) R[i]+=R[i-1];
		for (int i=cnt-1;i>=1;i--) L[i]+=L[i+1];
		for (int i=1;i<=cnt;i++)
		{
			if (a[i].id==1) ans[a[i].q]+=R[a[i].num-1];
			else ans[a[i].q]+=L[a[i].num+1];
		}
		res=n-1;
		for (int i=1;i<=n;i++)
		{
			res=min(res,ans[i]);
		}
		cout << res << endl;
	}
	return 0;
}