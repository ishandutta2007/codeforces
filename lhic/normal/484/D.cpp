#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>


using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1000100;

int n;

long long arr[MAX_N];

long long dp[MAX_N];


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%I64d", &arr[i]);
	
	dp[0] = 0;
	dp[1] = 0;
	int lst = 0;
	for (int i = 1; i < n; ++i)
	{
		dp[i + 1] = dp[i];
		if (arr[i] == arr[i - 1])
		{
			lst = i;
			continue;
		}
		
		if (lst == i - 1)
		{
			dp[i + 1] = max(dp[i + 1], dp[i - 1] + abs(arr[i] - arr[i - 1]));
			continue;
		}
		
		if ((arr[i - 1] > arr[lst]) != (arr[i] > arr[i - 1]))
			lst = i - 1;
		//cout << i << " " << lst << "\n";
		
		dp[i + 1] = max(dp[i + 1], max(dp[lst] + abs(arr[i] - arr[lst]), dp[lst + 1] + abs(arr[i] - arr[lst + 1])));
	}
	
	cout << dp[n];
	
	
	return 0;
}