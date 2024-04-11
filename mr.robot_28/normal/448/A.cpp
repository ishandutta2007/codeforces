#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int a1, a2, a3, b1, b2, b3, n;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	cin >> n;
	int sum = (a1 + a2 + a3) / 5 + ((a1 + a2 + a3) % 5 != 0);
	int sum1 = (b1 +b2 + b3) / 10 + ((b1+ b2 + b3) % 10 != 0);
	if(sum + sum1 <= n)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}