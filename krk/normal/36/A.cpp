#include <cstdio>
#include <string>
#include <set>
#include <iostream>
using namespace std;

int n;
string s;
int lst = -1;
set <int> S;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == '1')
			if (lst == -1) lst = i;
			else { S.insert(i - lst); lst = i; }
	printf("%s\n", S.size() == 1? "YES": "NO");
	return 0;
}