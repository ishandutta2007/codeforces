#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int Maxn = 205;

int n;
string s[Maxn];
bool taken[Maxn];
int res;

int getRes(int l)
{
	int r = n + 1;
	int res = 0;
	while (l <= n && r <= 2 * n) {
		while (r <= 2 * n && taken[r]) r++;
		if (r > 2 * n) break;
		if (s[l][0] < s[r][0]) l++;
		else if (s[l][0] > s[r][0]) r++;
		else { res++; l++; r++; }
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		cin >> s[i];
	sort(s + 1, s + n + 1); sort(s + n + 1, s + 2 * n + 1);
	res = getRes(1);
	int cur = 0;
	for (int i = 1; i <= n; i++)
		for (int j = n + 1; j <= 2 * n; j++) if (!taken[j]) {
			cur += s[i][0] == s[j][0]; taken[j] = true;
			if (cur + getRes(i + 1) == res) {
				printf("%s %s%s", s[i].c_str(), s[j].c_str(), i == n? "\n": ", ");
				break;
			}
			cur -= s[i][0] == s[j][0]; taken[j] = false;
		}
	return 0;
}