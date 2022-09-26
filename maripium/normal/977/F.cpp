#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
map<int,int> mp;
int pre[N];
int f[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;++i) cin >> a[i];
	int res = 0;
	for (int i = 1;i <= n;++i) {
		if (!mp[a[i] - 1]) f[i] = 1;
		else {
			f[i] = f[mp[a[i] - 1]] + 1;
			pre[i] = mp[a[i] - 1];
		}
		mp[a[i]] = i;
		res = max(res, f[i]);
	}
	int st;
	for (int i = 1;i <= n;++i) {
		if (f[i] == res) st = i;
	}
	vector<int> vres;
	while(st) {
		vres.push_back(st);
		st = pre[st];
	}
	reverse(vres.begin(), vres.end());
	cout << vres.size() << endl;
	for (int i = 0;i < vres.size();++i) cout << vres[i] << ' ';
}