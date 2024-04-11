#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
	scanf("%d", &n);
	cin >> s;
	if (s == "0") { printf("0\n"); return 0; }
	printf("1");
	for (int i = 1; i < s.length(); i++)
		if (s[i] == '0') printf("0");
	printf("\n");
	return 0;
}