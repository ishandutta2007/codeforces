#include <iostream>
using namespace std;
int cnt[3];
int main()
{
	int n,a;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		cnt[a-1]++;
	}
	printf("%d",n-max(cnt[0],max(cnt[1],cnt[2])));
}