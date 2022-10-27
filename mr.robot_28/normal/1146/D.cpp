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
int gcd(int a, int b)
{
	if(a * b == 0)
	{
		return a + b;
	}
	else if(a > b)
	{
		return gcd(a % b, b);
	}
	else
	{
		return gcd(a, b % a);
	}
}
main()
{
	int m, a, b;
	cin >> m >> a >> b;
	int u = gcd(a, b);
	int k = m / u + 1;
	int ans = (k + 1) * k / 2 * u - (k * u - m- 1) * k;
	int cnt = 1;
	vector <int> A(2e5 + 10), B(2e5 + 10);
	A[0] = 1;
	B[cnt] = 0;
	while(true)
	{
		cnt++;
		B[cnt] = B[cnt - 1] >= b ? B[cnt - 1] - b: B[cnt - 1] + a;
		if(A[B[cnt]])
		{
			break;
		}
		A[B[cnt]] = 1;
	}
	cnt--;
	//cout << cnt;
	int i = 0, j = 1;
	while(i < a + b && i <= m)
	{
		ans -= (i / u + 1);
		while(j <= cnt && B[j] <= i)
		{
			j++;
		}
		ans += j - 1;
		//cout << j << " ";
		i++;
	}
	cout << ans;
    return 0;
}