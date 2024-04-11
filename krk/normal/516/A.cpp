#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
string s;
string res;

int main()
{
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == '2') res += "2";
		else if (s[i] == '3') res += "3";
		else if (s[i] == '4') res += "322";
		else if (s[i] == '5') res += "5";
		else if (s[i] == '6') res += "53";
		else if (s[i] == '7') res += "7";
		else if (s[i] == '8') res += "7222";
		else if (s[i] == '9') res += "7332";
	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());
	cout << res << endl;
	return 0;
}