#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
int d[N];
int par[N];
int mg = 0;
int c[N];
int find(int i) {
	return par[i] == i ? i : (par[i] = find(par[i]));
}
void merge(int i, int j) {
	i = find(i); j = find(j);
	if (i == j)return;
	par[i] = j;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		puts("0"); return 0;
	}
	vector <int> d1(n);
	int L = 0;
	for(int i = 0; i < n; i++)par[i] = i;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		d1[u]++;
		c[u] = c[v] = 1;
		if (u != v) {
			d[u]++; d[v]++;
			merge(u, v);
		}
		else L++;
	}
	vector <int> cnt(n);
	int mx1 = 0, mx2 = 0;
	for(int i = 0; i < n; i++) {
		cnt[find(i)] += d1[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(cnt[i] > mx1)
		{
			mx2 = mx1;
			mx1 = cnt[i];
		}
		else if(cnt[i] > mx2)
		{
			mx2 = cnt[i];
		}
	}
	if(mx2 > 0)
	{
		cout << 0;
		return 0;
	}
	long long ans = 0;
	ans += 1LL * L*(L - 1) / 2;
	for(int i = 0; i < n; i++){
		ans += 1LL * d[i] * (d[i] - 1) / 2;
	}
	ans += 1LL * (m - L)*L;
	printf("%lld\n", ans);
	return 0;
}