#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int N = 1e5 + 10;
int t;
int a[N], b[N];
void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	for(int i = 1; i <= n; i++) cout << b[i] << " ";
	cout << endl;
	return;
}

int main() {
	for(cin >> t; t--; solve());
	return 0;
}