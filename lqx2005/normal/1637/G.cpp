#include <bits/stdc++.h>
#define TRACE(x) cerr << #x <<" = " << x << endl
#define _ << " _ " <<
#define sz(a) int((a).size())
using namespace std;
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10;
int cnt[30];
int ansx[N], ansy[N], tot = 0;
multiset<int> s;
void done(int x, int y) { ansx[++tot] = x, ansy[tot] = y; }
void solve(int n, int d) {
	// cout << n <<" " << d << endl;
    if(n <= 0) return;
    int k = 1;
    for(; k < n; k <<= 1);
    if(k == n) {
        cnt[__lg(k * d)]++;
        return solve(n - 1, d);
    }
    for(int i = n; i > (k >> 1); i--) done(i * d, (k - i) * d), cnt[__lg(k * d)]++;
    cnt[__lg((k >> 1) * d)]++;
    solve(n - (k >> 1), d * 2);
    solve(k - n - 1, d);
    return;
}
void solver() {
	tot = 0;
	int n;
	cin >> n;
	if(n <= 2) return cout << -1 << endl, void();
	int h = -1;
	for(int i = 0; i <= 20; i++) cnt[i] = 0;
	solve(n, 1);
	vector<int> num;
	for(int i = 0; i <= 20; i++) {
		if(cnt[i]) h = i;
		// cout << cnt[i] <<" ";
		for(int j = 1; j <= cnt[i]; j++) {
			num.push_back(i);
		}
	}
	// cout << endl;
	if(cnt[num[0]] == 1) {
		for(int i = 1; i <= num[1] - num[0]; i++) {
			int x = 1 << num[0], y = 1 << num[2];
			done(x, y);
			done(y - x, x + y);
			cnt[num[0]]--, cnt[num[2]]--;
			num[0]++, num[2]++;
			cnt[num[0]]++, cnt[num[2]]++;
		}
	}
	for(int i = 0; i < h; i++) {
		if(!cnt[i]) continue;
		done(1 << i, 1 << i);
		for(int j = 1; j <= cnt[i] - 2; j++) {
			done(0, 1 << i), done(1 << i, 1 << i);
		}
		done(0, 1 << (i + 1));
		cnt[i + 1] += cnt[i], cnt[i] = 0;
	}
	// s.clear();
	// for(int i = 1; i <= n; i++) s.insert(i);
	cout << tot << endl;
	for(int i = 1; i <= tot; i++) {
		cout << ansx[i] <<" " << ansy[i] << endl;
		// assert(s.find(ansx[i]) != s.end());
		// s.erase(s.find(ansx[i]));
		// assert(s.find(ansy[i]) != s.end());
		// s.erase(s.find(ansy[i]));
		// s.insert(ansx[i] + ansy[i]), s.insert(abs(ansx[i] - ansy[i]));
	}
	// for(auto v : s) cout << v <<" ";
	// cout << endl;
}
int main() {
    int t;
    for(cin >> t; t--; ) {
		solver();
    }
    return 0;
}