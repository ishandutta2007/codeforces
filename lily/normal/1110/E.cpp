#include <bits/stdc++.h>
using namespace std;

#define N 1000005

/*
map <vector<int>, bool> vis;


queue <vector <int>> q;


vector<int> op(vector<int> x, int y) {
	x[y] = x[y + 1] + x[y - 1] - x[y];
	return x;
}

int main() {
	vector <int> start;
	int yy;
	while (cin >> yy) start.push_back(yy);
	vis[start] = 1;
	q.push(start);
	while (!q.empty()){
		vector<int> x = q.front(); q.pop();
		
		for (auto v : x) {
			cerr << v << " ";
		}

		cerr << endl;

		for (int i = 1; i < x.size() - 1; i++) {
			vector <int> y = op(x, i);
			if (!vis[y]) {
				vis[y] = 1;
				q.push(y);
			}
		}
	}
}
*/

int n;
int a[N], b[N];
int c[N], d[N];

int main() {
	cin >> n;
	for (int i =1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}
	if (a[1] != b[1] || a[n] != b[n]) {
		puts("No");
		return 0;
	}
	for (int i = 1; i < n; i++) c[i] = abs(a[i + 1] - a[i]);
	for (int i = 1; i < n; i++) d[i] = abs(b[i + 1] - b[i]);
	sort(c + 1, c + n); sort(d + 1, d + n);
	for (int i = 1; i < n; i++) if (c[i] != d[i]) {
		puts("No");
		return 0;
	}
	puts("Yes");


}