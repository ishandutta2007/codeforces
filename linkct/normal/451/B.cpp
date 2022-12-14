#include <stdio.h>
#include <algorithm>
using namespace std;

struct data
{
	int n, p;
	bool operator < (const data& x) const
	{
		return n < x.n;
	}
}arr[100005];
bool cmp(const data& a, const data& b){return a.p < b.p;}

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &arr[i].n);
		arr[i].p = i;
	}
	sort(arr + 1, arr + 1 + n);
	for(i = 1; i <= n; i ++)
		if(arr[i].p != i)
		{
			for(j = i + 1; j <= n; j ++)
				if(arr[j].p == i)
					break;
			sort(arr + 1, arr + 1 + n, cmp);
			for(k = i; k <= (i + j) / 2; k ++)
				swap(arr[k], arr[i + j - k]);
			for(k = i; k <= n; k ++)
				if(arr[k].n < arr[k - 1].n)
				{
					printf("no\n");
					return 0;
				}
			printf("yes\n%d %d\n", arr[j].p, arr[i].p);
			return 0;
		}
	printf("yes\n1 1\n");
	return 0;
}