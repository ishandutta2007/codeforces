#include <iostream>
using namespace std;
int cnt[2];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a%2]++;
	}
	if (n==k)
	{
		if (cnt[1]%2)
		printf("Stannis");
		else
		printf("Daenerys");
	}
	else if ((n-k)/2>=cnt[1])
	printf("Daenerys");
	else if ((n-k)/2>=cnt[0])
	{
		if (k%2)
		printf("Stannis");
		else
		printf("Daenerys");
	}
	else
	{
		if ((n-k)%2)
		printf("Stannis");
		else
		printf("Daenerys");
	}
}