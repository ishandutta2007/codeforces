#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100100;

int n,d;
int a[MaxN];
long long ans;

int main()
{
	cin>>n>>d;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
	{
		int p=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		if (i+1>=p) continue;
		//i+1 , i+2 , ... , p-1
		ans+=(long long)(p-i-1)*(p-i)/2;
	}
	cout<<ans<<endl;
	return 0;
}