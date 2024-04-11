#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;
const int Maxn = 100005;

string s;
int x, y;
int L0[Maxn], L1[Maxn];
int R0[Maxn], R1[Maxn];
ll cur;
ll res;

int main()
{
	getline(cin, s);
	cin >> x >> y;
	if (x > y) {
		reverse(s.begin(), s.end());
		swap(x, y);
	}
	for (int i = 0; i < s.length(); i++) {
		if (i) { L0[i] = L0[i - 1]; L1[i] = L1[i - 1]; }
		if (s[i] == '0' || s[i] == '?') L0[i]++;
		else L1[i]++;
	}
	for (int i = int(s.length()) - 1; i >= 0; i--) {
		R0[i] = R0[i + 1]; R1[i] = R1[i + 1];
		if (s[i] == '0') R0[i]++;
		else R1[i]++;
	}
	int zer = 0, ones = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '0') { cur += ll(y) * ones; zer++; }
		else { cur += ll(x) * zer; ones++; }
	res = cur;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '?') {
			if (i) cur -= ll(x) * L0[i - 1];
			cur -= ll(y) * R0[i + 1];
			if (i) cur += ll(y) * L1[i - 1];
			cur += ll(x) * R1[i + 1];
			res = min(res, cur);
		}
	cout << res << endl;
    return 0;
}