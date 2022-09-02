#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
const int N = 1e5;
int a[N];
int o[N];
int b[N];
// f_i(X) = \min_{Y \leq X} f_{i-1}(Y) + |Y - a[i]|

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] -= i;
	}
	priority_queue<int> que;
	
	o[0] = a[0];
	que.push(a[0]);
	for (int i = 0; i < n; ++i) {
		que.push(a[i]);
		if (a[i] < o[i-1]) {
			que.push(a[i]);
			que.pop();
		}
		o[i] = que.top();
	}
	b[n-1] = o[n-1];
	for (int i = n-2; i >= 0; --i) {
		b[i] = min(o[i], b[i+1]);
	}
	ll res = 0;
	for (int i = 0; i < n; ++i) res += abs(a[i] - b[i]);
	cout << res << '\n';
}