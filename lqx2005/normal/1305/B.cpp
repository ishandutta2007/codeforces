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
char s[N];
int posl[N], posr[N], ans[N];
void solve() {
	int n;
	cin >> (s + 1);
	n = strlen(s + 1);
	int totl = 0, totr = 0;
	for(int i = 1; i <= n; i++) if(s[i] == '(') posl[++totl] = i;
	for(int i = n; i >= 1; i--) if(s[i] == ')') posr[++totr] = i;
	posl[++totl] = n + 1, posr[++totr] = 0;
	int tot = 0;
	for(int i = 1; i <= min(totl, totr); i++) {
		if(posl[i] < posr[i]) {
			ans[++tot] = posl[i], ans[++tot] = posr[i];
		}
	}
	if(tot == 0) {
		cout << 0 << endl;
		return;
	}
	sort(ans + 1, ans + tot + 1);
	cout << 1 << endl;
	cout << tot << endl;
	for(int i = 1; i <= tot; i++) cout << ans[i] <<" ";
	cout << endl;
	return;
}

int main() {
	solve();
	return 0;
}