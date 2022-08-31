#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;




const int SIZE = 1e6 + 100;


int a[SIZE];

const long long inf = 1e17;


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
	}


	long long answer = 0;
	long long maxVal1 = -inf, maxVal2 = -inf;
	for (int i = 0; i < n; i++)
	{
		maxVal1 = max(maxVal1, answer - a[i] );
		maxVal2 = max(maxVal2, answer + a[i] );
		long long curans = max(a[i] + maxVal1, -a[i] + maxVal2); 
		answer = max(answer, curans);
	}

	printf("%I64d\n", answer);


	return 0;
}