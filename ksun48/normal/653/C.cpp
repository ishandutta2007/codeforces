#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int t[150000];
int ans = 0;
set<pair<int,int> > l;
vector<int> bad;
int good(int i){
	if(i == n-1 || i == -1) return 1;
	if(i % 2 == 0) return (t[i] < t[i+1]);
	if(i % 2 == 1) return (t[i] > t[i+1]);
}
void test(int i, int j){
	if(i == j || i >= n || j >= n || i < 0 || j < 0) return;
	if(i > j){
		test(j,i);
		return;
	}
	for(int k = 0; k < bad.size(); k++){
		if(bad[k] != i && bad[k] != i-1 && bad[k] != j && bad[k] != j-1){
			return;
		}
	}
	swap(t[i],t[j]);
	if(good(i) && good(i-1) && good(j) && good(j-1)){
		l.insert(make_pair(i,j));
		//cout << i << " " << j << endl;
	}
	swap(t[i],t[j]);
	return;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}
	for(int i = 0; i < n; i++){
		if(!good(i)) bad.push_back(i);
	}
	if(bad.size() >= 6){
		cout << 0 << endl;
		return 0;
	}
	for(int k = 0; k < bad.size(); k++){
		for(int i = 0; i < n; i++){
			test(i,bad[k]);
			test(i,bad[k]+1);
			test(i,bad[k]-1);
		}
	}
	cout << l.size() << endl;
}