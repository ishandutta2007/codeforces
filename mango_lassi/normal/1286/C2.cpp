#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 100;
const int C = 26;

vector<string> ask(int a, int b) {
	cout << "? " << a+1 << ' ' << b+1 << endl;

	int m = (b-a+1) * (b-a+2) / 2;

	vector<string> res(m);
	for (int i = 0; i < m; ++i) {
		cin >> res[i];
		sort(res[i].begin(), res[i].end());
	}
	sort(res.begin(), res.end());
	return res;
}

string solve(int x, int y) {
	int n = y-x+1;
	vector<string> s1 = ask(x, y);
	if (n == 1) return s1[0];

	vector<string> s2 = ask(x+1, y);
	vector<string> pref(n);
	
	int a = 0;
	for (int i = 0; i < s2.size(); ++i, ++a) {
		while (s2[i] != s1[a]) {
			pref[(int)s1[a].size() - 1] = s1[a];
			++a;
		}
	}
	while (a < s1.size()) {
		pref[(int)s1[a].size() - 1] = s1[a];
		++a;
	}

	string res(n, '_');
	vector<int> cou(C, 0);
	for (int i = 0; i < n; ++i) {
		vector<int> nxt(C, 0);
		for (auto c : pref[i]) ++nxt[c - 'a'];
		for (int j = 0; j < C; ++j) {
			if (nxt[j] > cou[j]) res[i] = 'a' + j;
		}
		cou = nxt;
	}
	return res;
}

// Total count of character c in strings of length k
// Count in first k + last k characters of the string: (k+1) * cou[c][k] - k * cou[c][k+1]
int cou[C][N];

// i'th character appears min(i, k) times in strings of length k
// min(i, k+1) - min(i, k)

// Must have 2(k+1) <= n
int pos(int c, int k, int n) {
	int pref1 = 0;
	int pref2 = 0;
	pref1 = cou[c][0] - (cou[c][k+1] - cou[c][k]);
	if (k > 0) {
		pref2 = cou[c][0] - (cou[c][k] - cou[c][k-1]);
	}
	return pref1 - pref2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int k = (n+1) / 2;
	string pref = solve(0, k-1);
	if (k == n) {
		cout << "! " << pref << endl;
	} else {
		vector<string> counts = ask(0, n-1);
		for (auto& str : counts) {
			int k = str.size();
			for (auto c : str) ++cou[c - 'a'][k-1];
		}

		string res(n, '_');
		for (int i = 0; i < k; ++i) res[i] = pref[i];

		for (int i = 0; i < n-k; ++i) {
			for (int c = 0; c < 26; ++c) {
				int tar = pos(c, i, n) - (res[i] == ('a' + c));
				if (tar == 1) res[n-1-i] = 'a' + c;
				// if (pos(c, i, n) > 0) cerr << (char)('a' + c) << ' ' << i << ' ' << pos(c, i, n) << '\n';
			}
		}
		cout << "! " << res << '\n';
	}
}