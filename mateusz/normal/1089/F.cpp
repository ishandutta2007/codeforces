#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " " << x << endl;
#define int long long
const int N = 1e6+9;
vector <int> dziel;
set <pair<int,int> > dp[N];
int odl[N],n,mod;
void bfs() {
	priority_queue <pair<int,pair<int,int> > > q;
	q.push(make_pair(1, make_pair(0, 0)));
	while(!q.empty()) {
		int v = q.top().second.first;
		int od = -q.top().first;
		int nr = q.top().second.second;
		q.pop();
		// debug(v);
		if(odl[v] != 0) continue;
		odl[v] = od;
		dp[v] = dp[nr];
		// debug(v);
		// for(int i = 0; i < dp[v].size(); i++) {
		// 	debug(dp[v][i]);
		// }
		if(v !=0) {
			int zm = odl[v] - odl[nr];
			auto h = dp[v].upper_bound(make_pair(zm, -1));
			if(h == dp[v].end() || (*h).first != zm) dp[v].insert(make_pair(zm, 1));
			else {
				int zmienna = (*h).second;
				dp[v].erase(h);
				dp[v].insert(make_pair(zm, zmienna + 1));
			}
		}
		for(int i = 0; i < dziel.size(); i++) {
			int u = v + dziel[i];
			// debug(u);
			// debug(dziel[i]);
			u%=mod;
			if(odl[u] == 0) {
				q.push(make_pair(-odl[v] - dziel[i], make_pair(u, v)));
			}
		}
	}
}
void jebnij() {
	printf("NO");
	exit(0);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin>>n;
	// if(n !=6) jebnij();
	for(int i = 2; i <=sqrt(n); i++) {
		if(n%i == 0) {
			dziel.push_back(i);
			if(i != n/i) dziel.push_back(n/i);
		}
	}
	sort(dziel.begin(), dziel.end());
	if(dziel.size() == 0) jebnij();
	mod = dziel[0];
	// debug(mod);
	dziel.erase(dziel.begin());
	bfs();
	int ind = (n - 1) % mod;
	// debug(ind);
	if(odl[ind] == 0 || odl[ind] > n - 1) jebnij();
	cout<<"YES\n";
	if(odl[ind] == n - 1) {
		cout << dp[ind].size() << endl;
	}
	else {
		cout << dp[ind].size() + 1 << endl;
		cout << (n - 1 - odl[ind]) / mod << " " << n / mod << endl;
	}
	for(auto v:dp[ind]) {
		cout << v.second << " " << n/v.first << endl;
	}
}