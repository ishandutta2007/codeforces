#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	#define int long long
	int n, k;
	cin >> n >> k;
	if(n == k)
	{
		for(int i = 0; i < n; i++)
		{
			cout << 1;
		}
		return 0;
	}
	int a = (n - k) / 2;
	int i = 0;
	while(i < n)
	{
		for(int j = 0; j < min(n - i, a); j++)
		{
			cout << 1;
		}
		i += a;
		if(i < n)
		{
			cout << 0;
			i++;
		}
	}
	return 0;
}