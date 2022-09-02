#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int ind(char c) {
	return c - 'a';
}

bool fill(vector<int>& tmp, vector<bool>& used) {
	cout << "YES\n";
	int i = 0;
	for (int j = 0; j < tmp.size(); ++j) {
		if (tmp[j] == -1) {
			while(used[i]) ++i;
			used[i] = true;
			tmp[j] = i;
		}
		cout << (char)('a' + tmp[j]);
	}
	cout << '\n';
	return true;	
}

bool loop(const string& s, const string& a, vector<int> tmp, vector<bool> used, int i, bool less, int k) {
	// IF less, MUST BE a <= s
	int n = s.size();
	for (; i < n; ++i) {
		int ai = ind(a[i]);
		int si = ind(s[i]);
		if (tmp[si] != -1) {
			if (tmp[si] == ai) continue;
			if ((ai < tmp[si]) == less) {
				return fill(tmp, used);
			} else return false;
		} else {
			for (int ji = 0; ji < k; ++ji) {
				if ((ji == ai) || ((ji < ai) == less)) continue;
				if (! used[ji]) {
					used[ji] = true;
					tmp[si] = ji;
					return fill(tmp, used);
				}
			}
			if (! used[ai]) {
				used[ai] = true;
				tmp[si] = ai;
				continue;
			}
			return false;
		}
	}
	return fill(tmp, used); // s = a, e.g. s = abac, a = cbcd, b = daaa
}

bool solve() {
	int k;
	cin >> k;
	string s, a, b;
	cin >> s >> a >> b;
	int n = s.size();

	vector<int> tmp(k, -1);
	vector<bool> used(k, false);
	for (int i = 0; i < n; ++i) {
		int ai = ind(a[i]);
		int bi = ind(b[i]);
		int si = ind(s[i]);
		
		if (ai == bi) {
			if (tmp[si] != -1) {
				if (tmp[si] != ai) return false; // different pace repeats, e.g. s = aba, a = b = abb
				else continue;
			} else {
				if (used[ai]) return false; // character already used, e.g. s = abc, a = b = aba
				used[ai] = true;
				tmp[si] = ai;
			}
		} else {
			if (tmp[si] != -1) {
				if (tmp[si] < ai || bi < tmp[si]) return false; // Forced outside range, e.g. s = aa, a = ab, b = ac
				if (tmp[si] == ai) {
					return loop(s, a, tmp, used, i+1, true, k); // Try to match with a as lower bound
				} else if (tmp[si] == bi) {
					return loop(s, b, tmp, used, i+1, false, k); // Try to match with b as upper bound
				} else {
					return fill(tmp, used); // Forced inside range with no problem, e.g. s = aa, a = ba, b = bc
				}
			} else {
				for (int ji = ai + 1; ji < bi; ++ji) {
					if (! used[ji]) {
						used[ji] = true;
						tmp[si] = ji;
						return fill(tmp, used); // Can go inside range, e.g. s = ab, a = ba, b = bc
					}
				}
				if (! used[ai]) {
					used[ai] = true;
					tmp[si] = ai;
					if (loop(s, a, tmp, used, i+1, true, k)) return true; // Can go to a, e.g. s = ab, a = ba, b = bb
					used[ai] = false;
					tmp[si] = -1;
				}
				if (! used[bi]) {
					used[bi] = true;
					tmp[si] = bi;
					if (loop(s, b, tmp, used, i+1, false, k)) return true; // Can go to b, e.g. s = ab, a = ba, b = bb
					used[bi] = false;
					tmp[si] = -1;
				}
				return false; // Cannot go into range, e.g. s = abc, a = bcb, b = bcc
			}
		}
	}
	return fill(tmp, used); // a == b
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		bool fail = ! solve();
		if (fail) cout << "NO\n";
	}
}