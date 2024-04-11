#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int T, n, a[N], b[N], c[N];
priority_queue<int> pq;
void work() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		c[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	int cnt = 0, ans = 0;
	for(int i = 1; i <= n; i++) if(c[i] == 0) pq.push(i);
	for(int i = 1; i <= n; i++) if(c[i] >= 1) ans++;
	for(int i = 1; i <= n; i++) {
		if(pq.empty()) break;
		if(c[a[i]] > 1) {
			int x = pq.top();
			pq.pop();
			if(x == i) {
				if(!pq.empty()) {
					int y = pq.top();
					pq.pop();
					pq.push(x);
					x = y;
				}
			}
			if(x != i) c[a[i]]--, a[i] = x;
			else pq.push(x);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(pq.empty()) break;
		if(c[a[i]] > 1) {
			int x = pq.top();
			pq.pop();
			if(x == i) {
				if(!pq.empty()) {
					int y = pq.top();
					pq.pop();
					pq.push(x);
					x = y;
				}
			}
			if(x != i) c[a[i]]--, a[i] = x;
			else pq.push(x);
		}
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) {
		cout << a[i] <<" ";
	} 
	cout << endl;
	return;
}

int main() {
	cin >> T;
	for(; T--; ) work();
	return 0;
}