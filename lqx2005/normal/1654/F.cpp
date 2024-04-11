#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
const int N = 1 << 18;
int n;
char s[N + 10];
int id[N], cnt[26];
tuple<int, int, int> cur[N];
void solve() {
	cin >> n >> s;
	for(int i = 0; i < (1 << n); i++) cnt[s[i] - 'a'] = 1;
	for(int i = 1; i < 26; i++) cnt[i] += cnt[i - 1];
	for(int i = 0; i < (1 << n); i++) id[i] = cnt[s[i] - 'a'];
	for(int i = 2; i <= (1 << n); i <<= 1) {
		int tot = 0;
		for(int j = 0; j < (1 << n); j += i) {
			for(int k = 0; k < (i >> 1); k++) {
				cur[tot++] = make_tuple(id[j + k], id[j + k + (i >> 1)], j + k);
				cur[tot++] = make_tuple(id[j + k + (i >> 1)], id[j + k], j + k + (i >> 1));
			}
		}
		sort(cur, cur + tot);
		int rk = 1;
		id[get<2>(cur[0])] = 1;
		for(int j = 1; j < tot; j++) {
			if(get<0>(cur[j - 1]) == get<0>(cur[j]) && get<1>(cur[j - 1]) == get<1>(cur[j]));
			else rk++;
			id[get<2>(cur[j])] = rk;
		}
	}
	int ans = -1;
	for(int i = 0; i < (1 << n); i++) if(id[i] == 1) ans = i;
	for(int i = 0; i < (1 << n); i++) cout << s[i ^ ans];
	cout << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(t = 1; t--; ) {
		solve();
	}
    return 0;
}