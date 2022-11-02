//I hate you
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 200010
int n,m,s,d;
int a[maxn];
int b[maxn];
int ans[maxn],cnt;

int main()
{
	read(n),read(m),read(s),read(d);
	for (int i=1;i<=n;i++)	read(a[i]);
	sort(a+1,a+n+1);
	if (a[1]-1<s)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for (int i=1;i<n;i++)	b[i]=a[i+1]-a[i]-2;
	b[n]=1<<30;
	cnt=1;
	ans[cnt]=1;
	int pre=a[1]-1;
	for (int i=1;i<=n;i++)
	{
		if (b[i]>=s)
		{
			if (a[i]+1-pre>d)
			{
				printf("IMPOSSIBLE\n");
				return 0;
			}	else
			{
				cnt++;
				ans[cnt]=i+1;
				pre=a[i+1]-1;
			}
		}
	}
	printf("RUN %d\n",a[1]-1);
	pre=a[1]-1;
	for (int i=2;i<=cnt;i++)
	{
		printf("JUMP %d\n",a[ans[i]-1]+1-pre);
		pre=a[ans[i]-1]+1;
		if (ans[i]!=n+1)
		{
			printf("RUN %d\n",a[ans[i]]-1-pre);
			pre=a[ans[i]]-1;
		}	else
		{
			if (m!=pre)	printf("RUN %d\n",m-pre);
		}
	}
	return 0;
}