#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
typedef long long LL;



void work() {
	int n, a, b;
	cin >> n >> a >> b;
	int m1 = 0, m2 = 0;
	for (int i= 1 ; i <=a; i++) {
		int x;
		cin >> x;
		m1 = max(x, m1);
	}

	for (int i= 1 ; i <=b; i++) {
		int x;
		cin >> x;
		m2 = max(x, m2);
	}
	puts(m1 > m2 ? "YES" : "NO");
}

int main() {
	int T;
	cin >> T;
	while (T--) work();


}