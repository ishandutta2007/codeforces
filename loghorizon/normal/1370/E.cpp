#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const int N = 1000005;

int n, a[N], b[N], len;

char s[N], t[N], c[N];

PII q[N];

priority_queue<int, vector<int>, greater<int> > q1, q2;

int main() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	int c0 = 0, c1 = 0, d0 = 0, d1 = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') c0++;
		else c1++;
		if (t[i] == '0') d0++;
		else d1++;
	}
	if (c0 != d0 || c1 != d1) puts("-1");
	else {
		c0 = d0 = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0' && t[i] == '1') {
				c[i] = 'a';
				if (d0) {
					q[++len] = make_pair(b[d0], i);
					d0--;
				} else {
					a[++c0] = i;
				}
			} else if (s[i] == '1' && t[i] == '0') {
				c[i] = 'b';
				if (c0) {
					q[++len] = make_pair(a[c0], i);
					c0--;
				} else {
					b[++d0] = i;
				}
			}
		}
		sort(q + 1, q + 1 + len);
		for (int i = 1; i <= len; i++) {
			if (c[q[i].first] == 'a') {
				if (q1.empty() || q1.top() > q[i].first) {
					q1.push(q[i].second);
				} else {
					q1.pop();
					q1.push(q[i].second);
				}
			} else {
				if (q2.empty() || q2.top() > q[i].first) {
					q2.push(q[i].second);
				} else {
					q2.pop();
					q2.push(q[i].second);
				}
			}
		}
		printf("%d\n", (int)(q1.size() + q2.size()));
	}
	return 0;
}