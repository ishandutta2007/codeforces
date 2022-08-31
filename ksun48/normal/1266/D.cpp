#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> debt(n, 0);
	for(int i = 0; i < m; i++){
		int u, v;
		ll d;
		cin >> u >> v >> d;
		u--; v--;
		debt[u] += d;
		debt[v] -= d;
	}
	vector<pair<int, ll> > pos;
	vector<pair<int, ll> > neg;

	vector<int> a, b;
	vector<ll> money;
	for(int i = 0; i < n; i++){
		while(debt[i] > 0){
			if(neg.empty()) break;
			ll v = min(debt[i], -neg.back().second);
			a.push_back(i); b.push_back(neg.back().first); money.push_back(v);
			debt[i] -= v;
			neg.back().second += v;
			if(neg.back().second == 0){
				neg.pop_back();
				continue;
			}
		}
		while(debt[i] < 0){
			if(pos.empty()) break;
			ll v = min(-debt[i], pos.back().second);
			b.push_back(i); a.push_back(pos.back().first); money.push_back(v);
			debt[i] += v;
			pos.back().second -= v;
			if(pos.back().second == 0){
				pos.pop_back();
				continue;
			}
		}
		if(debt[i] > 0){
			pos.push_back({i, debt[i]});
			debt[i] = 0;
		}
		if(debt[i] < 0){
			neg.push_back({i, debt[i]});
			debt[i] = 0;
		}
	}
	cout << a.size() << '\n';
	for(int i = 0; i < (int)a.size(); i++){
		cout << a[i] + 1 << ' ' << b[i] + 1 << ' ' << money[i] << '\n';
	}
}