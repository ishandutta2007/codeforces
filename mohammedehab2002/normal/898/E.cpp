#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
vector<int> v,v2;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int x=sqrt(a);
		if (x*x==a)
		v2.push_back(1+(a==0));
		v.push_back(min(a-x*x,(x+1)*(x+1)-a));
	}
	int en=n/2;
	if (v2.size()>n/2)
	v=v2,en=v2.size()-n/2;
	sort(v.begin(),v.end());
	long long ans=0;
	for (int i=0;i<en;i++)
	ans+=v[i];
	printf("%I64d",ans);
}