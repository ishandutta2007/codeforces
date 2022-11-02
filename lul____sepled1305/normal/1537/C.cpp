#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, mini = 1e9;
		map<int,int> mp;
		cin>>n;
		vector<int> v;
		vector<pii> ans;
		for(int i=0;i<n;i++) {
			int a; cin>>a; v.push_back(a); mp[a]++;
		}
		sort(v.begin(),v.end());
		for(int i=1;i<n;i++) {
			if(v[i] - v[i-1] < mini) {
				mini = v[i] - v[i-1];
				ans.clear();
				ans.push_back({i-1,i});
			}
			else if(v[i] - v[i-1] == mini)
				ans.push_back({i-1,i});
		}
		if(n != 2) {
			for(int i=ans[0].second;i<n;i++)
				cout<<v[i]<<' ';
			for(int i=0;i<=ans[0].first;i++)
				cout<<v[i]<<' ';
			cout<<endl;
		}
		else {
			cout<<v[0]<<' '<<v[1]<<endl;
		}
	}
	return 0;
}