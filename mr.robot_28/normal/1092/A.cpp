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
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			char t = 'a' + i % k;
			cout << t;
		}
		cout << endl;
	}
	return 0;
}