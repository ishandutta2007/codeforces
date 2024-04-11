#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 201212

struct Node {
	int a, b;
	bool operator < (const Node &o) const {
		return a < o.a;
	}
} a[N];

int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].a);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i].b);
	sort(a + 1, a + n + 1);
	priority_queue <int> q;
	LL sum = 0; int last = -1;
	LL ans = 0;
	for (int i = 1; i <= n; ) {
		int j = i;
		while (last + 1 < a[i].a && q.size()) {
			ans += sum;
			sum -= q.top();
			q.pop();
			last++;
		}
		if (last == a[i].a - 1) ans += sum;
		last = a[i].a;
		while (a[j].a == a[i].a) {
			q.push(a[j].b);
			sum += a[j].b;
			j++;
		}
		if (q.size()) sum -= q.top(), q.pop();
		i = j;
	}
	while (q.size()) {
		ans += sum;
		sum -= q.top();
		q.pop();
	}
	cout << ans << endl;

}