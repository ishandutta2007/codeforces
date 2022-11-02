#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=200008;
int n,m,T; 
struct point
{
	ll x,id;
}a[N],ans[N];
ll s[N];
int cnt=0;
bool used[N];

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
bool cmp(point x,point y)
{
	return x.x<y.x;
}
bool cmp2(point x,point y)
{
	return x.id<y.id;
}
void work()
{
	cnt=0;
	n=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	s[0]=0;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i].x;
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]>=a[i].x) used[i]=1;
		else used[i]=0;
	}
	for (int i=n;i>=1;i--)
	{
		if (used[i]==0)
		{
			ans[++cnt]=a[i];
			return;
		}
		else ans[++cnt]=a[i];
	}
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
		sort(ans+1,ans+cnt+1,cmp2);
		cout << cnt << endl;
		for (int i=1;i<=cnt;i++) cout << ans[i].id << " ";
		cout << endl;
	}
	return 0;
}