#include<bits/stdc++.h>
using namespace std;
int a[255555],n,ans[555],cnt;
multiset<int> s;
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n*n;i++)
	{
		scanf("%d",&a[i]);
	}
	if (n==1)
	{
		printf("%d\n",a[1]);
		return 0;
	}
	sort(a+1,a+n*n+1);
	reverse(a+1,a+n*n+1);
	for (int i=1;i<=n*n;i++)
	{
		multiset<int>::iterator it=s.find(a[i]);
		if (it==s.end())
		{
			ans[++cnt]=a[i];
			for (int j=1;j<cnt;j++)
			{
				s.insert(gcd(a[i],ans[j]));
				s.insert(gcd(ans[j],a[i]));  
			}
		}
		else
		{
			s.erase(it);
		}
	}
	for (int i=1;i<=cnt;i++) printf("%d ",ans[i]);
	return 0;
}