#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 55;

int n, k;
string s[Maxn];
set <int> S;
int a[Maxn];

int main()
{
	cin >> n >> k;
	for (int i = k; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i < k; i++)
		a[i] = i;
	S.insert(k);
	for (int i = k; i <= n; i++)
		if (s[i] == "YES") {
			a[i] = *S.begin(); S.erase(a[i]);
			S.insert(a[i - (k - 1)]);
		} else a[i] = a[i - (k - 1)];
	for (int i = 1; i <= n; i++)
		printf("%c%c%c", 'A' + (a[i] / 26), 'a' + (a[i] % 26), i + 1 <= n? ' ': '\n');
	return 0;
}