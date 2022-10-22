#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int Maxl = 26;

int f[Maxl];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		f[s[i] - 'a']++;
	int res = 0;
	for (int i = 0; i < Maxl; i++)
		res += f[i] % 2;
	if (res <= 1) printf("First\n");
	else if (res % 2) printf("First\n");
	else printf("Second\n");
	return 0;
}