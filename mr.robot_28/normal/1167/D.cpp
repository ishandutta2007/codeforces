#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	#define int long long
	int n;
	cin >> n;
	string s;
	cin >> s;
	int sum = 0, max = 0;
	vector <int> used(s.size(), 0);
	vector <int> d(s.size());
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(')
		{
			sum++;
		}
		else
		{
			sum--;
		}
		if(sum > max)
		{
			max = sum;
		}
		d[i] = sum;
	}
	for(int i = 0;i < d.size(); i++)
	{
		if(d[i] > max / 2)
		{
			used[i] = 1;
		}
		if(d[i] == max / 2 && s[i] == ')')
		{
			used[i] = 1;
		}
		cout << used[i];
	}
    return 0;
}