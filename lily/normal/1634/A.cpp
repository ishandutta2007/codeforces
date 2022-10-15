#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second




int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		string t = s;
		reverse(t.begin(), t.end());
		if (k == 0) cout << 1 << endl;
		else if (s == t) cout << 1 << endl;
		else cout << 2 << endl;
	}

}