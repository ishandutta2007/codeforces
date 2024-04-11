#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, a, b;
	cin >> n;
	cin >> a >> b;
	int tmp = max(a, b);
	for(int i = 2; i <= n; i++) {
		scanf("%d %d", &a, &b);
		if(max(a, b) <= tmp) tmp = max(a, b);
		else if(min(a, b) <= tmp) tmp = min(a, b);
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}