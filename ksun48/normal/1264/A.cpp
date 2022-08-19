#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++) cin >> p[i];
	vector<int> lens;
	int cur = 0;
	for(int i = 0; i < n; i++){
		cur++;
		if(i == n-1 || p[i] != p[i+1]){
			lens.push_back(cur);
			cur = 0;
		}
	}
	int sum = n;
	int bm = n / 2;
	while(sum > bm && !lens.empty()){
		sum -= lens.back();
		lens.pop_back();
	}

	if(lens.size() < 3){
		cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
		return;
	}


	int cg = lens[0];
	int csum = 0;
	sum -= cg;
	for(int j = 1; j < (int)lens.size(); j++){
		csum += lens[j];
		if(csum > cg && sum - csum > cg){
			cout << cg << ' ' << csum << ' ' << sum - csum << '\n';
			return;
		}
	}
	cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}