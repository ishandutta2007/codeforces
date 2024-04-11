#include <bits/stdc++.h>
#define i64 long long
#define db double
#define x first
#define y second
using namespace std;
int T;
i64 n, s;
int main() {
	cin >> T;
	for(; T--; ) {
		cin >> n >> s;
		i64 m = n - (n + 1) / 2 + 1;
		cout << s / m << endl;
	}
	return 0;
}