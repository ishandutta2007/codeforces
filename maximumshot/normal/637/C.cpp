#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 2000;
int n, ans;
string s[maxn];

int f(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < 6; i++)
	if (a[i] != b[i])
		cnt++;
	return (cnt - 1) / 2;
}

int main() {
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	cin >> n;
	ans = 6;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		ans = min(ans, f(s[i], s[j]));
	cout << ans;
	return 0;
}