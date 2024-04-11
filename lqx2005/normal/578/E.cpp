#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
const int N = 1e5 + 10;
int n, to[N], st[N], LR[N];
char s[N];

int solve(vector<int> L, vector<int> R) {
	reverse(L.begin(), L.end()), reverse(R.begin(), R.end());
	for(int i = 1; i <= n; i++) {
		to[i] = 0;
		if(s[i] == 'L') {
			while(!R.empty() && R.back() <= i) R.pop_back();
			if(!R.empty()) to[i] = R.back(), R.pop_back();
		} else {
			while(!L.empty() && L.back() <= i) L.pop_back();
			if(!L.empty()) to[i] = L.back(), L.pop_back();
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += (to[i] == 0);
	return cnt - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> (s + 1);
	n = strlen(s + 1);
	vector<int> L, R;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'L') L.push_back(i);
		else R.push_back(i);
	}
	if(sz(L) == sz(R)) {
		if(solve(L, R) < solve(R, L)) {
			for(int i = 1; i <= n; i++) {
				s[i] ^= 'L' ^ 'R';
			}
		}
	} else if(sz(L) < sz(R)) {
		for(int i = 1; i <= n; i++) {
			s[i] ^= 'L' ^ 'R';
		}
	}
	L.clear(), R.clear();
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'L') L.push_back(i);
		else R.push_back(i);
	}
	cout << solve(L, R) << endl;
	L.clear(), R.clear();
	for(int i = 1; i <= n; i++) st[i] = 1;
	for(int i = 1; i <= n; i++) st[to[i]] = 0;
	for(int i = 1; i <= n; i++) {
		if(st[i]) {
			if(s[i] == 'L') L.push_back(i);
			else R.push_back(i);
			for(int j = i; j; j = to[j]) LR[i] = s[j] == 'R';
		}
	}
	if(!L.empty() && !R.empty() && LR[L[0]] && !LR[R[0]]) {
		for(int i = 2; i <= n; i++) {
			if(st[i] && (s[1] == 'R') == LR[i] && s[i] != s[1]) {
				st[to[1]] = 1, LR[to[1]] = LR[1];
				LR[1] = LR[i], LR[i] = 0;
				to[1] = i, st[i] = 0;
				break;
			}
		}
		L.clear(), R.clear();
		for(int i = 1; i <= n; i++) {
			if(st[i]) {
				if(s[i] == 'L') L.push_back(i);
				else R.push_back(i);
			}
		}
	}
	sort(L.begin(), L.end(), [&](int x, int y) {
		return LR[x] < LR[y];
	});
	sort(R.begin(), R.end(), [&](int x, int y) {
		return LR[x] > LR[y];
	});
	int str = -1;
	if(R.empty()) str = 0;
	else if(L.empty()) str = 1;
	else if(!LR[L[0]]) str = 0;
	else str = 1;
	if(!L.empty() && !R.empty()) assert(!LR[L[0]] || LR[R[0]]);
	int cnt = 0;
	for(int opt = str ^ 1; cnt < n; ) {
		int x = -1;
		if(opt == 1) {
			x = L.back();
			L.pop_back();
		} else {
			x = R.back();
			R.pop_back();
		}
		for(int i = x; i; i = to[i]) cout << i <<" ", opt = s[i] == 'R', cnt++;
	}
	cout << endl;
	return 0;
}