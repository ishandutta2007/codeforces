#include<bits/stdc++.h>
using namespace std;

vector<int> e[100000];
int v[1000000];
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	q.push(1);
	v[1] = 1;
	while (!q.empty()) {
		int t = q.top();
		cout << t << " ";
		q.pop();
		for (auto x : e[t]) {
			if (v[x] == 0) {
				v[x] = 1;
				q.push(x);
			}
		}
	}
}