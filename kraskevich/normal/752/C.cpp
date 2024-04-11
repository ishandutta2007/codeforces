#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int res = 0;
	set<char> was;
	for (char c : s) {
		bool clear = false;
		if (c == 'D' && was.count('U') || c == 'U' && was.count('D'))
			clear = true;
		if (c == 'L' && was.count('R') || c == 'R' && was.count('L'))
			clear = true;
		if (clear) {
			was = set<char>();
			res++;
		}
		was.insert(c);
	}
	cout << res + 1 << endl;
}