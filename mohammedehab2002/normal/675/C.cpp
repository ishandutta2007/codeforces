#include <iostream>
#include <map>
using namespace std;
map<long long,int> cnt;
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	long long sum=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		sum+=a;
		cnt[sum]++;
		ans=max(ans,cnt[sum]);
	}
	printf("%d",n-ans);
}