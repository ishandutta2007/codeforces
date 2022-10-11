#include <iostream>
using namespace std;
int arr[500005],cnt[1000005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	int r=0,al=0,ar=-1;
	for (int i=0;i<n;i++)
	{
		while (r<n)
		{
			cnt[arr[r]]++;
			if (cnt[arr[r]]==1)
			k--;
			if (k<0)
			{
				cnt[arr[r]]--;
				k++;
				break;
			}
			r++;
		}
		if (r-i>ar-al)
		{
			al=i;
			ar=r;
		}
		cnt[arr[i]]--;
		if (!cnt[arr[i]])
		k++;
	}
	printf("%d %d",al+1,ar);
}