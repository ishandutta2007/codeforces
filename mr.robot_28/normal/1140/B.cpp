#include <iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int a;
		string s;
		cin >> a >> s;
		int l = 0, r =0;
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == '<')
			{
				l++;
			}
			else
			{
				break;
			}
		}
		for(int j = s.size() - 1; j >= 0; j--)
		{
			if(s[j] == '>')
			{
				r++;
			}
			else
			{
				break;
			}
		}
		cout << min(l, r) << endl;
	}
	return 0;
}