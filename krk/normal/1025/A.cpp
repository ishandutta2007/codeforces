#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int freq[Maxl];
int n;
string s;

int main()
{
	cin >> n;
	if (n == 1) { printf("Yes\n"); return 0; }
	cin >> s;
	for (int i = 0; i < n; i++)
		freq[s[i] - 'a']++;
	for (int i = 0; i < Maxl; i++)
		if (freq[i] > 1) { printf("Yes\n"); return 0; }
	printf("No\n");
	return 0;
}