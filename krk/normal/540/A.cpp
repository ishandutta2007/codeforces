#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s, t;
int res;

int Dist(char a, char b)
{
	int da = a - '0';
	int db = b - '0';
	if (da > db) swap(da, db);
	return min(db - da, 10 + da - db);
}

int main()
{
	scanf("%d", &n);
	cin >> s >> t;
	for (int i = 0; i < n; i++)
		res += Dist(s[i], t[i]);
	printf("%d\n", res);
	return 0;
}