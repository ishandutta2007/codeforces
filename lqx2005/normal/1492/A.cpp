#include <bits/stdc++.h>
#define x first
#define y second
#define pi pair<int, int>
#define db double
#define i64 long long
#define u64 unsigned long long
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		i64 p, a, b, c;
		cin >> p >> a >> b >> c;
		cout << min(min((a - p % a) % a, (b - p % b) % b), (c - p % c) % c) << endl;
	}
    return 0;
}