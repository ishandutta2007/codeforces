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
	int n, count = 0;
	string a;
	cin >> n >> a;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == '8')
		{
			count ++;
		}
	}
	int count1 = 0;
	while(count > 0 && n > 10)
	{
		count1++;
		n -= 11;
		count--;
	}
	cout << count1;
	return 0;
}