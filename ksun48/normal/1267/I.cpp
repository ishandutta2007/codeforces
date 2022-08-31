#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>, bool> asked;

void done(){
	cout << '!' << '\n';
	cout << flush;
}

bool less_query(int i, int j){
	if(i == -1) return true;
	if(j == -1) return false;
	if(asked.find({i, j}) == asked.end()){
		cout << '?' << ' ' << i + 1 << ' ' << j + 1 << '\n';
		cout << flush;

		char c;
		cin >> c;		
		asked[{i, j}] = (c == '>');
	}
	return asked[{i, j}];
}

void solve(){
	asked = {};
	int n;
	cin >> n;
	vector<pair<int,int> > z;
	for(int i = 0; i < n; i++){
		int a = i;
		int b = i + n;
		if(less_query(a, b)) swap(a, b);
		z.push_back({a, b});
	}
	sort(z.begin(), z.end(), [&](pair<int,int> x, pair<int,int> y){
		return less_query(y.first, x.first);
	});
	swap(z[0].second, z[1].first);
	z.erase(z.begin());
	if(less_query(z[0].first, z[0].second)) swap(z[0].first, z[0].second);
	int need = n - 2;
	for(int i = 0; i < need; i++){
		int which = 0;
		for(int j = 1; j < (int)z.size(); j++){
			if(less_query(z[which].first, z[j].first)){
				which = j;
			}
		}
		assert(z[which].first != -1);
		swap(z[which].first, z[which].second);
		z[which].second = -1;
	}
	done();
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}