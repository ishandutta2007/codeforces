#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum = n / 3 * 2;
	n = n % 3;
	if (n > 0)
	{
		sum ++;
	}
	cout << sum;
    return 0;
}