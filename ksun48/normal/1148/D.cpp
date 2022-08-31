#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int> > p1, p2;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a < b){
			p1.emplace_back(a, i+1);
		} else {
			p2.emplace_back(b, i+1);
		}
	}
	if(p1.size() > p2.size()){
		sort(p1.begin(), p1.end());
		reverse(p1.begin(), p1.end());
		cout << p1.size() << '\n';
		for(pair<int,int> x : p1){
			cout << x.second << ' ';
		}
		cout << '\n';
	} else {
		sort(p2.begin(), p2.end());
		cout << p2.size() << '\n';
		for(pair<int,int> x : p2){
			cout << x.second << ' ';
		}
		cout << '\n';
	}
}