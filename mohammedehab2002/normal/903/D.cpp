#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
map<int,int> cnt;
int main()
{
	int n;
	scanf("%d",&n);
	long double sum=0,ans=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ans+=(long long)i*a-sum;
		ans+=cnt[a+1];
		ans-=cnt[a-1];
		sum+=a;
		cnt[a]++;
	}
	cout << setprecision(100) << ans;
}