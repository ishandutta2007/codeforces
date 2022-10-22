#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n;
string s;
bool res;

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < n && !res; i++) if (s[i] == '*')
		for (int j = 1; j <= n && !res; j++) {
			bool ok = true;
			for (int l = 1; l <= 4 && ok; l++)
				ok = i + j * l < n && s[i + j * l] == '*';
			res = ok;
		}
	printf("%s\n", res? "yes": "no");
	return 0;
}