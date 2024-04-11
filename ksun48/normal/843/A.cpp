#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	vector<pair<int,int> > f;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		f.push_back(make_pair(a[i], i));
	}
	sort(f.begin(), f.end());
	vector<vector<int> > ans;
	int vis[n];
	for(int i = 0; i < n; i++) vis[i] = 0;
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		vector<int> nans;
		int t = i;
		while(1){
			vis[t] = 1;
			nans.push_back(t);
			t = f[t].second;
			if(t == i) break;
		}
		ans.push_back(nans);
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d", ans[i].size());
		for(int j = 0; j < ans[i].size(); j++){
			printf(" %d", 1+ ans[i][j]);
		}
		printf("\n");
	}
}