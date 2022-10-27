#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n % 4 == 0 || (n + 1) % 4 == 0)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
	return 0;
}