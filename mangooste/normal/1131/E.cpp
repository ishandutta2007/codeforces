#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct one {
	bool all;
	char left_type, right_type;
	ll cnt_left, cnt_right;
	vector<ll> cnt;

	one() {}
};

one get(string s) {
	int n = s.size();

	one res;
	res.all = (s == string(n, s[0]));
	res.left_type = s[0];
	res.right_type = s.back();
	res.cnt_left = res.cnt_right = 1;

	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1])
			res.cnt_left++;
		else
			break;
	}

	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == s[i + 1])
			res.cnt_right++;
		else
			break;
	}

	res.cnt.resize(26);
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && s[i] == s[j])
			j++;

		res.cnt[s[i] - 'a'] = max(res.cnt[s[i] - 'a'], (ll) j - i);
		i = j;
	}

	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	one now = get(s);

	for (int i = 1; i < n; i++) {
		cin >> s;
		one cur = get(s);

		one nnow;
		nnow.all = (cur.all && now.all && cur.left_type == now.left_type);

		nnow.left_type = cur.left_type;
		nnow.right_type = cur.right_type;

		if (cur.all && now.left_type == cur.left_type)
			nnow.cnt_left = (ll) s.size() * (now.cnt_left + 1) + now.cnt_left;
		else
			nnow.cnt_left = cur.cnt_left;

		if (cur.all && now.right_type == cur.right_type)
			nnow.cnt_right = (ll) s.size() * (now.cnt_right + 1) + now.cnt_right;
		else
			nnow.cnt_right = cur.cnt_right;

		nnow.cnt = cur.cnt;
		for (int i = 0; i < 26; i++)
			if (now.cnt[i])
				nnow.cnt[i] = max(nnow.cnt[i], 1 + cur.cnt_right * (cur.right_type - 'a' == i) + cur.cnt_left * (cur.left_type - 'a' == i));

		if (cur.all)
			nnow.cnt[cur.left_type - 'a'] = max(nnow.cnt[cur.left_type - 'a'], 
			                                (ll) s.size() * (now.cnt[cur.left_type - 'a'] + 1) + now.cnt[cur.left_type - 'a']);

		now = nnow;
	}

	cout << *max_element(now.cnt.begin(), now.cnt.end()) << '\n';;
}