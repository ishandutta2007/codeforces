#include <bits/stdc++.h>
using namespace std;
#define MX 100000
int arr[100005],u[MX+5],cnt[MX+5];
vector<int> d[MX+5];
bool b[MX+5];
int coprime(int x)
{
	int ret=0;
	for (int i:d[x])
	ret+=cnt[i]*u[i];
	return ret;
}
void update(int x,int a)
{
	for (int i:d[x])
	cnt[i]+=a;
}
int main()
{
	for (int i=1;i<=MX;i++)
	{
		for (int j=i;j<=MX;j+=i)
		d[j].push_back(i);
		if (i==1)
		u[i]=1;
		else if ((i/d[i][1])%d[i][1]==0)
		u[i]=0;
		else
		u[i]=-u[i/d[i][1]];
	}
	int n;
	scanf("%d",&n);
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ans=max(ans,(long long)a);
		b[a]=1;
	}
	for (int g=1;g<=MX;g++)
	{
		stack<int> s;
		for (int i=MX/g;i>0;i--)
		{
			if (!b[i*g])
			continue;
			int c=coprime(i);
			while (c)
			{
				if (__gcd(i,s.top())==1)
				{
					ans=max(ans,1LL*i*s.top()*g);
					c--;
				}
				update(s.top(),-1);
				s.pop();
			}
			update(i,1);
			s.push(i);
		}
		while (!s.empty())
		{
			update(s.top(),-1);
			s.pop();
		}
	}
	printf("%I64d",ans);
}