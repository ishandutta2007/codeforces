#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[3000];

int main(){
	int n; cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a+n);
	vector< vector<int> > ans;
	for (int i=0; i<3; i++){
		if (i != 0){
			bool flag = false;
			for (int j=0; j+1<n; j++) if (a[j].first==a[j+1].first && a[j].second<a[j+1].second){
				swap(a[j], a[j+1]);
				flag = true;
				break;
			}
			if (!flag){
				cout << "NO" << endl;
				return 0;
			}
		}
		ans.push_back(vector<int>());
		for (int j=0; j<n; j++)
			ans[i].push_back(a[j].second);
	}
	cout << "YES" << endl;
	for (int i=0; i<3; i++, cout << endl)
		for (int j=0; j<n; j++)
			cout << ans[i][j]+1 << ' ';
	return 0;
}