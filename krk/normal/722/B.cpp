#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const string W = "aeiouy";
const int Maxn = 105;

int n;
int p[Maxn];

int main()
{
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	getline(cin, s);
	bool ok = true;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int tot = 0;
		for (int j = 0; j < s.length(); j++)
			if (W.find(s[j]) != string::npos) tot++;
		ok &= tot == p[i];
	}
	printf("%s\n", ok? "YES": "NO");
	return 0;
}