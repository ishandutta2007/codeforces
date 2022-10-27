#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	#define int long long
	string s;
	cin >> s;
	vector <int> pref(s.size()), post(s.size());
	if(s.size() < 3)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] == 'v' && s[i - 1] == 'v')
		{
			pref[i] = pref[i - 1] + 1;
		}
		else
		{
			pref[i] = pref[i - 1];
		}
	}
	for(int i = s.size() - 2; i >= 0; i--)
	{
		if(s[i] == 'v' && s[i + 1] == 'v')
		{
			post[i] = post[i + 1] + 1;
		}
		else
		{
			post[i] = post[i + 1];
		}
	}
	int sum = 0;
	for(int i = 1; i < s.size() - 1; i++)
	{
		if(s[i] == 'o')
		{
			sum += pref[i - 1] * post[i + 1];
		}
	}
	cout << sum;
	return 0;
}