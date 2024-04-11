#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
int funct(int r)
{
	int sum = 0;
	int a = 0, b = 0, k = 1, k1 = 0;
	while(k1 < r)
	{
		a = a + min(r - k1, k);
		k1 += min(r - k1, k);
		k *= 2;
		b = b + min(r - k1, k);
		k1 += min(r - k1, k);
		k *= 2;
	}
	sum += (a % CONST) * (a % CONST) % CONST;
	sum += (b %CONST) * ((b + 1) % CONST) % CONST;
	return sum % CONST;
}
main()
{
	int l, r;
	cin >> l >> r;
//	cout <<funct(r);
	cout << (funct(r) - funct(l - 1) + CONST) % CONST;
    return 0;
}