#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

string s;

vector<string> vv;

string tr(string s) {
	int now = 0;
	while (now + 1 < s.size() && s[now] == '0')
		++now;
	return s.substr(now);
}

int main() {
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); ++i)
		sum += (s[i] - '0');
	sum %= 3;
	if (sum != 0) {
		for (int i = s.size() - 1; i >= 0; --i) {
			if ((s[i] - '0') % 3 == sum) {
				string t = s.substr(0, i) + s.substr(i + 1);
				t = tr(t);
				if (!t.empty())
					vv.push_back(t);
				break;
			}
		}
		int p1 = -1;
		for (int i = s.size() - 1; i >= 0; --i) {
			if ((s[i] - '0') % 3 == 0)
				continue;
			if ((s[i] - '0') % 3 == sum)
				continue;
			if (p1 == -1) {
				p1 = i;
				continue;
			}
			string t = s.substr(0, i) + s.substr(i + 1, p1 - i - 1) + s.substr(p1 + 1);
			t = tr(t);
			if (!t.empty())
				vv.push_back(t);
			break;
		}
	}
	else {
		s = tr(s);
		if (!s.empty())
			vv.push_back(s);
	}
	string ans = "";
	for (string t: vv)
		if (t.size() > ans.size())
			ans = t;
	if (ans.empty())
		cout << -1 << "\n";
	else
		cout << ans << "\n";
	return 0;
}