#include <iostream>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	long long prevT = 0;
	long long quSize = 0;

	long long mxSize = 0;
	for (int i = 0; i < n; i++)
	{
		long long t, k;
		scanf("%I64d%I64d", &t, &k);
		quSize = quSize - (t - prevT);
		quSize = max(0LL, quSize);
		quSize += k;
		mxSize = max(mxSize, quSize);

		prevT = t;
	}

	long long ansT = prevT + quSize;

	printf("%I64d %I64d", ansT, mxSize);



	return 0;
}