#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ll;
const int N = 5e6 + 10;
int ans = 0;
ll p10[19], L, R;
int pl[19], pr[19];
int cnt[10];
int getmn(int n) {
	static int num[19];
	memset(num, 0, sizeof(num));
	int tot = 0;
	for(int i = 1; i <= 9; i++) tot += cnt[i];
	if(tot > n) return 0;
	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= cnt[i]; j++) {
			num[--tot] = i;
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		if(pr[i] > num[i]) return 1;
		if(pr[i] < num[i]) return 0;
	}
	return 1;
}
int getmx(int n) {
	static int num[19];
	memset(num, 0, sizeof(num));
	int tot = n;
	for(int i = 9; i >= 1; i--) {
		for(int j = 1; j <= cnt[i]; j++) {
			if(tot == 0) return 0;
			num[--tot] = i;
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		if(pl[i] < num[i]) return 1;
		if(pl[i] > num[i]) return 0;
	}
	return 1;
}

int check(vector<int> num, ll L, ll R) {
	memset(cnt, 0, sizeof(cnt));
	cnt[0] = 1e9;
	for(int x : num) cnt[x]++;
	int siz = sz(num);
	for(int i = 18; i >= 0; i--) {
		if(siz > i + 1) return 0;
		if(pl[i] == pr[i]) {
			cnt[pl[i]]--;
			if(cnt[pl[i]] < 0) return 0;
			if(pl[i]) siz--;
		} else {
			for(int j = pl[i] + 1; j <= pr[i] - 1; j++) if(cnt[j]) return 1;
			if(cnt[pl[i]]) {
				cnt[pl[i]]--;
				if(getmx(i)) {
					return 1;
				}
				cnt[pl[i]]++;
			}
			if(cnt[pr[i]]) {
				cnt[pr[i]]--;
				if(getmn(i)) {
					return 1;
				}
				cnt[pr[i]]++;
			}
			return 0;
		}
	}
	if(siz > 0) return 0;
	return 1;
}
void dfs(int x, vector<int> s) {
	if(x == 10) {
		if(!s.empty()) {
			ans += check(s, L, R);			
		}
		return;
	} 
	for(; sz(s) <= 18; ) {
		dfs(x + 1, s);
		s.push_back(x);
	}
	return;
}
int main() {
	p10[0] = 1;
	for(int i = 1; i <= 18; i++) p10[i] = p10[i - 1] * 10;
	cin >> L >> R;
	ll tl = L, tr = R;
	for(int i = 0; i <= 18; i++) pl[i] = tl % 10, tl /= 10, pr[i] = tr % 10, tr /= 10;
	dfs(1, {});
	cout << ans << endl;
	return 0;
}