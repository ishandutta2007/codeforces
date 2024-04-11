#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int Maxn = 100005;

string s;
int sum[Maxn];
int m;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> s;
	for (int i = 0; i + 1 < s.length(); i++)
		sum[i + 1] = sum[i] + (s[i] == s[i + 1]);
	cin >> m;
	while (m--) {
		int l, r; cin >> l >> r;
		cout << sum[r - 1] - sum[l - 1] << endl;
	}
	return 0;
}