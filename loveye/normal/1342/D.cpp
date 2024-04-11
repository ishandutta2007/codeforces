#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int N = 2e5 + 5;
int n,k,a[N],c[N],pre[N];
multiset<int> s;
vector<vector<int> > ans;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1;i <= n;++i)
		cin >> a[i],s.insert(a[i]);
	c[0] = n;
	for(int i = 1;i <= k;++i) {
		cin >> c[i];
		if(c[i] != c[i-1]) pre[i] = i-1;
		else pre[i] = pre[i-1];
	}
	while(!s.empty()) {
		v.clear();
		int p = k;
		while(p) {
			auto it = s.lower_bound(p);
			if(it == s.end() || *it > p) {
				if(it == s.begin()) break;
				--it;
			}
			v.push_back(*it),s.erase(it);
			if(v.size() == c[p]) p = pre[p];
		}
		if(v.size()) ans.push_back(v);
	}
	cout << ans.size() << endl;
	for(int i = 0;i < ans.size();++i) {
		cout << ans[i].size();
		for(int j = 0;j < ans[i].size();++j)
			cout << ' ' << ans[i][j];
		cout << endl;
	}
	return 0;
}