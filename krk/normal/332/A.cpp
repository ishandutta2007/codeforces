#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n;
string s;
int res;

int main()
{
	cin >> n >> s;
	for (int i = n; i < s.length(); i += n)
		res += s[i - 3] == s[i - 2] && s[i - 2] == s[i - 1];
	printf("%d\n", res);
	return 0;
}