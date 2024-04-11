#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;
int a[200005];
int cnt[200005];
vector<pair<int, pair<int, int> > > vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) cnt[a[i]]++;
	
	int mx = 0, mx_i;
	for(int i = 0; i <= 200000; i++){
		if(mx < cnt[i]){
			mx = cnt[i];
			mx_i = i;
		}
	}
	
	int l;
	for(int i = 1; i <= n; i++){
		if(a[i] == mx_i){
			l = i;
			break;
		}
	}
	for(int i = l-1; i >= 1; i--){
		if(a[i] < a[i+1]){
		vec.push_back(make_pair(1, make_pair(i, i+1)));
		}else{
			vec.push_back(make_pair(2, make_pair(i, i+1)));
		}
		a[i] = a[i+1];
	}
	for(int i = l+1; i <= n; i++){
		if(a[i] == mx_i) continue;
		if(a[i-1] < a[i]){
			vec.push_back(make_pair(2, make_pair(i, i-1)));
		}else{
			vec.push_back(make_pair(1, make_pair(i, i-1)));
		}
		a[i] = a[i-1];
	}
	
	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << "\n";
	}
	flush(cout);
	
	return 0;
}