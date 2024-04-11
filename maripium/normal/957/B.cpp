#include<bits/stdc++.h>
using namespace std;

bool valid(vector<int> a,vector<int> b) {
	vector<int> ans;
	for(int i = 0;i < a.size();++i) {
		for(int j = 0;j < b.size();++j) {
			if(a[i] == b[j]) ans.push_back(a[i]);
 		}
	}
	return (ans.size() == 0 || (ans.size() == a.size() && ans.size() == b.size()));
}
int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	int n,m;
	cin >> n >> m;
	char c[55][55];
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;++j) 
			cin >> c[i][j];
	vector<int> row[55];
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < m;++j) {
			if(c[i][j] == '#') row[i].push_back(j);
		}
	}
	for(int i = 0;i < n;++i) sort(row[i].begin(),row[i].end());
	for(int i = 0;i < n;++i) {
		for(int j = i + 1;j < n;++j) {
			if(!valid(row[i],row[j])) return cout << "NO" << endl,0;
		}
	}
	cout << "YES" << endl;
}