#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<i64, int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2000 + 10;
int T;
int ask(vector<int> a, vector<int> b) {
	cout << "? " << sz(a) <<" " << sz(b) << endl;
	for(int x : a) cout << x <<" ";
	cout << endl;
	for(int x : b) cout << x <<" ";
	cout << endl;
	string ans;
	cin >> ans;
	if(ans == "FIRST") return 1;
	if(ans == "SECOND") return -1;
	assert(ans != "WASTED");
	return 0;
}
mt19937 rnd(__builtin_ia32_rdtsc());

void solve() {
	int n, k;
	cin >> n >> k;
	int key = -1;
	for(int i = 1; i <= 30; i++) {
		int x = rnd() % n + 1;
		if(x == key) continue;
		if(key == -1 || ask({x}, {key}) == 1) key = x;
	}
	vector<int> pos, s;
	s.push_back(key);
	for(int i = 1; i <= n; i++) if(i != key) pos.push_back(i);
	reverse(pos.begin(), pos.end());
	for(int i = 1; ; i <<= 1) {
		if(i > sz(pos)) break;
		vector<int> tmp(pos.end() - i, pos.end());
		if(ask(tmp, s) == 0) {
			pos.erase(pos.end() - i, pos.end());
			s.insert(s.end(), tmp.begin(), tmp.end());
		} else break;
	}
	for(int i = sz(s) >> 1; i > 0; i >>= 1) {
		if(i > sz(pos)) continue;
		vector<int> tmp1(pos.end() - i, pos.end()), tmp2(s.begin(), s.begin() + i);
		if(ask(tmp1, tmp2) == 0) {
			pos.erase(pos.end() - i, pos.end());
		}
	}
	cout << "! " << pos.back() << endl;
	return;
}

int main() {
	for(cin >> T; T--; solve());
	return 0;
}