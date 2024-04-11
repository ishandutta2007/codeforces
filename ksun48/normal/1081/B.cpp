#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int,int> freq;
	vector<vector<int> > same(n+1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = n - a[i];
		freq[a[i]]++;
		same[a[i]].push_back(i);
	}
	vector<int> col(n);
	int r = 1;
	for(int i = 1; i <= n; i++){
		if(same[i].size() % i != 0){
			cout << "Impossible" << '\n';
			return 0;
		}
		for(int j = 0; j < same[i].size(); j++){
			col[same[i][j]] = r + j / i;
		}
		r += same[i].size() / i;
	}
	cout << "Possible" << '\n';
	for(int i = 0; i < n; i++){
		cout << col[i] << ' ';
	}
	cout << '\n';
}