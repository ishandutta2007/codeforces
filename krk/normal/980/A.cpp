#include <bits/stdc++.h>
using namespace std;

string s;
int a, b;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'o') b++;
		else if (s[i] == '-') a++;
	if (b == 0 || a % b == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}