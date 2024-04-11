#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , n , a[maxn] , b[maxn] , m , s1 , s2 , s3;

int main()
{
	int i , j , k , l;
	cin >> T;
	while (T--)
	{
		scanf("%d",&n);
		for (i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		if (n < 10)
		{
			printf("0 0 0\n");
			continue;
		}
		for (i = n ; i >= 1 ; i--)
			if (i == n) b[i] = n+1;
			else if (a[i] != a[i+1]) b[i] = i+1;
			else b[i] = b[i+1];
		m = 0;
		for (i = n/2 ; i >= 1 ; i--)
			if (b[i] <= n/2+1)
			{
				m = b[i];
				break;
			}
		if (m == 0)
		{
			printf("0 0 0\n");
			continue;
		}
		s1 = s2 = s3 = 0;
		for (i = 1 ; i <= n ; i++)
		{
			j = b[i];
			if (j+j-1 > n) break;
			k = b[j+j-1];
			if (k+j-1 > n) break;
			l = b[k+j-1];
			if (l <= m)
			{
				s1 = j-1;
				s2 = k-j;
				s3 = m-k;
			}
		}
		printf("%d %d %d\n",s1,s2,s3);
	}
	return 0;
}