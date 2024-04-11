#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
using namespace std;
typedef pair<int, int> pii;
const int N = 1e4 + 10;
int p[N], vis[N];
int ask(int x) {
	cout << "? " << x << endl;
	int a;
	cin >> a;
	return a;
}
void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) vis[i] = p[i] = 0;
	for(int i = 1; i <= n; i++) {
		vector<int> cir;
		while(1) {
			int now = ask(i);
			if(vis[now]) break;
			cir.push_back(now);
			vis[now] = 1;
		}
		for(int j = 0; j < sz(cir); j++) p[cir[j]] = cir[(j + 1) % sz(cir)];
	}
	cout << "! ";
	for(int i = 1; i <= n; i++) cout << p[i] <<" ";
	cout << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}