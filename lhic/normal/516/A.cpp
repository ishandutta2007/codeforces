#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

vector<char> v;
string s;
int n;

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '0' || s[i] == '1')
			continue;
		if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7')
			v.push_back(s[i]);
		if (s[i] == '4')
			v.push_back('3'), v.push_back('2'), v.push_back('2');
		if (s[i] == '6')
			v.push_back('5'), v.push_back('3');
		if (s[i] == '8')
			v.push_back('7'), v.push_back('2'), v.push_back('2'), v.push_back('2');
		if (s[i] == '9')
			v.push_back('7'), v.push_back('3'), v.push_back('3'), v.push_back('2');
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); ++i)
		cout << v[i];
	return 0;
}