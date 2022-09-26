#include <bits/stdc++.h>
using namespace std;

int k;
string s, a, b;
bool found;
int match[26];
int f[26];

int get(int l,int r) {
	if (l > r) return 0;
	return f[r] - (l ? f[l - 1] : 0);
}

void modify(int u,int v) {
	match[u] = v;
	for (int i = v; i < 26; ++i) {
		f[i]--;
	}
}

int find_first(int l = 0) {
	for (int i = l; i < 26; ++i) if (get(i, i)) return i;
	return -1;
}

int find_last(int r = 25) {
	for (int i = r; i >= 0; --i) if (get(i, i)) return i;
	return -1;
}

void reset(int u,int v) {
	if (match[u] == -1) return;
	match[u] = -1;
	for (int i = v; i < k; ++i) {
		f[i]++;
	}
}

void go(int id,bool fa,bool fb) {
	if (found) return;
	if (id == int(a.size())) {
		if (found) return;
		found = true;
		for (int i = 0; i < k; ++i) if (match[i] == -1) {
			modify(i, find_first());
		}
		cout << "YES\n";
		for (int i = 0; i < k; ++i) {
			cout << char(match[i] + 'a');
		}
		cout << '\n';
		return;
	}
	if (~match[s[id] - 'a']) {
		if (!fa && match[s[id] - 'a'] < a[id] - 'a') return;
		if (!fb && match[s[id] - 'a'] > b[id] - 'a') return;
		int nfa = fa | (match[s[id] - 'a'] > a[id] - 'a');
		int nfb = fb | (match[s[id] - 'a'] < b[id] - 'a');
		go(id + 1, nfa, nfb);
		return;
	}
	if (!fa && !fb) {
		if (get(a[id] - 'a', b[id] - 'a') == 0) return;
		if (get(a[id] - 'a' + 1, b[id] - 'a' - 1)) {
			modify(s[id] - 'a', find_first(a[id] - 'a' + 1));
			go(id + 1, 1, 1);
			if (found) return;
		}
		if (get(a[id] - 'a', a[id] - 'a')) {
			modify(s[id] - 'a', a[id] - 'a');
			go(id + 1, 0, (a[id] < b[id]));
			if (found) return;
			reset(s[id] - 'a', a[id] - 'a');
		}
		if (get(b[id] - 'a', b[id] - 'a')) {
			modify(s[id] - 'a', b[id] - 'a');
			go(id + 1, (a[id] < b[id]), 0);
			if (found) return;
			reset(s[id] - 'a', b[id] - 'a');
		}
	} else if (!fa) {
		if (get(a[id] - 'a', k - 1) == 0) return;
		if (get(a[id] - 'a' + 1, k - 1)) {
			modify(s[id] - 'a', find_first(a[id] - 'a' + 1));
			go(id + 1, 1, 1);
			if (found) return;
		}
		else {
			modify(s[id] - 'a', a[id] - 'a');
			go(id + 1, 0, 1);
			if (found) return;
			reset(s[id] - 'a', a[id] - 'a');
		}
	} else if (!fb) {
		if (get(0, b[id] - 'a') == 0) return;
		if (get(0, b[id] - 'a' - 1)) {
			modify(s[id] - 'a', find_last(b[id] - 'a' - 1));
			go(id + 1, 1, 1);
			if (found) return;
		}
		else {
			modify(s[id] - 'a', b[id] - 'a');
			go(id + 1, 1, 0);
			if (found) return;
			reset(s[id] - 'a', b[id] - 'a');
		}
	} else {
		modify(s[id] - 'a', find_first());
		return go(id + 1, 1, 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int tt; cin >> tt;
	while (tt--) {
		found = false;
		cin >> k >> s >> a >> b;
		for (int i = 0; i < k; ++i) f[i] = i + 1, match[i] = -1;
		go(0, 0, 0);
		if (!found) {
			cout << "NO\n";
		}
	}
}