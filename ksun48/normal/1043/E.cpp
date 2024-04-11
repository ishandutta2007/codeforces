#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<LL> x(n);
	vector<LL> y(n);
	vector<pair<LL,int> > slist;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		x[i] *= -1;
		y[i] *= -1;
		slist.push_back({x[i]-y[i], i});
	}
	sort(slist.begin(), slist.end());
	vector<int> idx(n);
	for(int i = 0; i < n; i++){
		idx[i] = slist[i].second;
	}
	vector<LL> ans(n, 0);
	LL xsum = 0;
	LL ysum = 0;
	for(LL a = 0; a < n; a++){
		xsum += x[idx[a]];
		ans[a] += a * x[idx[a]] + (n-1-a) * y[idx[a]];
		ans[a] -= xsum;
		ans[a] += ysum;
		ysum += y[idx[a]];
	}
	for(LL a = 0; a < n; a++){
		ans[a] += xsum;
	}
	vector<LL> realans(n);
	for(int a = 0; a < n; a++){
		realans[idx[a]] = ans[a];
	}
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		realans[u] -= max(x[u] + y[v], x[v] + y[u]);
		realans[v] -= max(x[u] + y[v], x[v] + y[u]);
	}
	for(int a = 0; a < n; a++){
		cout << -realans[a] << " ";
	}
	cout << endl;
}