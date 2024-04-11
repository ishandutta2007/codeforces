#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a , b;
	cin >> a >> b;
	for(int i = a + 1; i <= 11000; i++)
	{
		int cnt = 0;
		for(int j = 2; j * j <= i; j++)
		{
			if(i % j == 0)
				cnt++;
		}
		if(cnt < 1 && i != b)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(cnt < 1 && i == b)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	return 0;
}