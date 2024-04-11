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

int n;

long long pw(long long x, int y)
{
	long long ans = 1;
	while (y > 0)
	{
		while (!(y & 1))
			x = (x * x) % n, y /= 2;
		--y;
		ans = (ans * x) % n;
	}
	return ans;
}


int main()
{
	cin >> n;
	if (n == 1)
	{
		cout << "YES\n1";
		return 0;
	}
	
	if (n == 4)
	{
		cout << "YES\n1 3 2 4";
		return 0;
	}
	
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			cout << "NO";
			return 0;
		}
	}
	
	
	cout << "YES\n";
	cout << 1 << " ";
	
	for (int i = 1; i < n - 1; ++i)
		cout << pw(i, n - 2) + 1 << " ";
	
	
	cout << n;
	
	
	
	return 0;
}