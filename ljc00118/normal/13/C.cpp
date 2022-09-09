#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

priority_queue <int> q;
LL ans = 0;
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		q.push(t);
		if(q.top() > t) {
			ans += (LL)(q.top() - t);
			q.pop();
			q.push(t);
		}
	}
	printf("%lld\n", ans);
	return 0;
}