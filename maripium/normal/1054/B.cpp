#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];
int fw[N];
map<int,int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int ptr = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > ptr) return cout << i << '\n',0;
		mp[a[i]] = 1;
		while (mp[ptr]) ptr++;
	}
	cout << -1 << '\n';
}