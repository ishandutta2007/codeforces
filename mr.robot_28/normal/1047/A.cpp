#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n % 3 == 1)
	{
		cout << 1 << " " << 2 << " " << n - 3;
	}
	else if(n % 3 == 2)
	{
		cout << "1 2 " << n - 3;
	}
	else
	{
		cout << 1 << " " << 1 << " " << n - 2;
	}
	return 0;
}