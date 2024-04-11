#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int N = 105, M = 55;
int n, m;
string s[N], st = "", ed = "", z = "";
int ss = 0, cnt = 0;
bool cmp(int a, int b) {
	for (int i = 0; i < m; i++)
		if (s[a][i] != s[b][m - i - 1]) return false;
	return true;
}
bool judge(int a) {
	for (int i = 0; i < m; i++)
		if (s[a][i] != s[a][m - i - 1]) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		bool ok = false;
		for (int j = 1; j < i; j++)
			if (cmp(i, j)) cnt += m * 2, ok = true, st += s[i], ed = s[j] + ed;
		if (!ok && judge(i)) ss = m, z = s[i]; 
	}
	cout << cnt + ss << endl << st + z + ed << endl;
	return 0;
}