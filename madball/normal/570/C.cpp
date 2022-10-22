#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	ll n, m, i, cur;
	char c;
	ll cntgood = 0;
	cin >> n >> m;
	vector<char> s(n);
	for (i = 0; i < n; ++i) {
		cin >> s[i];
		if (i && (s[i] == '.') && (s[i - 1] == '.'))
			++cntgood;
	}
	for (i = 0; i < m; ++i) {
		cin >> cur >> c;
		--cur;
		if ((s[cur] == '.') != (c == '.')) {
			if (c == '.') {
				if ((cur < n - 1) && (s[cur + 1] == '.'))
					++cntgood;
				if (cur && (s[cur - 1] == '.'))
					++cntgood;
			}
			else {
				if ((cur < n - 1) && (s[cur + 1] == '.'))
					--cntgood;
				if (cur && (s[cur - 1] == '.'))
					--cntgood;
			}
		}
		s[cur] = c;
		cout << cntgood << '\n';
	}
}