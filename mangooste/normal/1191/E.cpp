#include <bits/stdc++.h>

using namespace std;

inline void First_wins() {
	cout << "tokitsukaze\n";
	exit(0);
}

inline void Second_wins() {
	cout << "quailty\n";
	exit(0);
}

inline void Draw() {
	cout << "once again\n";
	exit(0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (n == k)
		First_wins();
	vector<char> pref(n + 1, true);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] && (s[i] == s[0]);
	vector<char> suf(n + 1, true);
	for (int i = n - 1; i >= 0; i--)
		suf[i] = suf[i + 1] && (s[i] == s.back());
	if (pref.back())
		First_wins();
	for (int i = 0; i + k <= n; i++) {
		bool ok = true;
		ok &= pref[i];
		ok &= suf[i + k];
		if (i != 0 && i + k != n)
			ok &= s[i - 1] == s[i + k];
		if (ok)
			First_wins(); 
	}

	bool can = false;
	array<set<int>, 2> poses;
	for (int i = k; i < n; i++)
		poses[s[i] - '0'].insert(i);
	for (int i = 0; i + k <= n; i++) {
		for (int j = 0; j < 2; j++) {
			bool can1;
			if (poses[j ^ 1].size())
				can1 = *poses[j ^ 1].rbegin() - *poses[j ^ 1].begin() + 1 <= k;
			else
				can1 = true;
			bool can2;
			if (poses[j].size())
				can2 = max(*poses[j].rbegin(), i + k - 1) - min(i, *poses[j].begin()) + 1 <= k;
			else
				can2 = true;
			can |= !can1 && !can2;
		}
		if (i + k != n)
			poses[s[i + k] - '0'].erase(i + k);
		poses[s[i] - '0'].insert(i);
	}
	if (can)
		Draw();
	else
		Second_wins();
}