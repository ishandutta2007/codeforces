#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 15e4 + 5;

int n;
int a[N];
priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;

signed main() {
	ios_base::sync_with_stdio(false); 	cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
		pq.push(make_pair(a[i],i));
	}
	
	while(!pq.empty()) {
		pair<int,int> u = pq.top();
		pq.pop();
		int v = u.first, pl = u.second;
		if (!pq.empty() && v == pq.top().first) {
			int pr = pq.top().second;
			pq.pop();
			a[pl] = 0;
			a[pr] <<= 1;
			pq.push(make_pair(a[pr],pr));
		}
	}
	
	vector<int> ans;
	for (int i = 1;i <= n;++i) if(a[i]) ans.push_back(a[i]);
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();++i) cout << ans[i] << ' ';
}