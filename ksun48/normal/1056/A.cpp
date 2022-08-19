#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	map<int,int> freq;
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		for(int j = 0; j < r; j++){
			int a;
			cin >> a;
			freq[a]++;
		}
	}
	for(auto x : freq){
		if(x.second == n){
			cout << x.first << ' ';
		}
	}
	cout << '\n';
}