#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int,int> > z;
	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j <= n+1; j++){
			if(abs(i-j) <= 1) z.push_back({i, j});
		}
	}
	cout << z.size() << '\n';
	for(pair<int,int> a : z) cout << a.first << ' ' << a.second << '\n';
}