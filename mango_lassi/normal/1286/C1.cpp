#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 100;
const int C = 26;
int cou[C][N]; // Count of character C in first k and last k characters

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	string res(n, '_');
	
	vector<string> s1 = ask(0, n-1);
	
	if (n > 1) {
		vector<string> s2 = ask(1, n-1);
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

		vector<int> cou(C, 0);
		for (int i = 0; i < n; ++i) {
			vector<int> nxt(C, 0);
			for (auto c : pref[i]) ++nxt[c - 'a'];
			for (int j = 0; j < C; ++j) {
				if (nxt[j] > cou[j]) res[i] = 'a' + j;
			}
			cou = nxt;
		}
	} else {
		res = s1[0];
	}
	cout << "! " << res << '\n';
}