#include <bits/stdc++.h>
using namespace std;

int maxm(int n){
	int res = 0;
	for(int i = 0; i < n; i++){
		res += min(i, n-1-i);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	if(m > maxm(n)){
		cout << -1 << '\n';
		return 0;
	}
	int extra = 0;
	while(n >= 2 && m <= maxm(n-1)){
		n--;
		extra++;
	}
	int A = 10000;
	int B = 9e8;
	vector<int> ans;
	for(int i = 1; i < n; i++){
		ans.push_back(A * i);
	}
	ans.push_back(A * (n + 2 * (maxm(n) - m)));
	for(int i = 0; i < extra; i++){
		ans.push_back(B + i);
	}
	for(int r : ans){
		cout << r << ' ';
	}
	cout << '\n';
}