#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	map<int,int> where;
	vector<int> pairs;
	for(int i = 0; i < n; i++){
		if(where.count(a[i])){
			pairs.push_back(i);
			pairs.push_back(where[a[i]]);
			where.erase(a[i]);
		} else {
			where[a[i]] = i;
		}
	}
	if(pairs.size() >= 4){
		pairs.resize(4);
		cout << "YES" << '\n';
		cout << pairs[0]+1 << ' '<< pairs[2]+1 << ' ' << pairs[1]+1 << ' ' << pairs[3]+1 << '\n';
		return 0;
	}

	map<int, int> numbers;
	vector<int> bad(n, 0);
	for(int i = 0; i < n; i++){
		if(numbers.count(a[i])) bad[i] = 1;
		numbers[a[i]] = i;
	}
	if(pairs.size() == 2){
		int p = a[pairs[0]];
		for(int i = 0; i < n; i++){
			if(a[i] == p) continue;
			if(numbers.count(p + p - a[i])){
				cout << "YES" << '\n';
				cout << pairs[0] + 1 << ' ' << pairs[1] + 1 << ' ' << i+1 << ' ' << numbers[p+p-a[i]]+1 << '\n';
				return 0;
			}
		}
	}
	vector<pair<int,int> > found(6e6, {-1, -1});
	for(int i = 0; i < n; i++){
		if(bad[i]) continue;
		for(int j = 0; j < i; j++){
			if(bad[j]) continue;
			int sum = a[i] + a[j];
			if(found[sum].first >= 0){
				cout << "YES" << '\n';
				cout << i+1 << ' ' << j+1 << ' ' << found[sum].first+1 << ' ' << found[sum].second+1 << '\n';
				return 0;
			}
			found[sum] = {i, j};
		}
	}
	cout << "NO" << '\n';
}