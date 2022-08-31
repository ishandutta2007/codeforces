#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int l, r;
	cin >> l >> r;
	for(int a = l; a <= r; a++){
		int b = a;
		vector<int> c;
		while(b > 0){
			c.push_back(b % 10);
			b /= 10;
		}
		sort(c.begin(), c.end());
		if(unique(c.begin(), c.end()) == c.end()){
			cout << a << '\n';
			exit(0);
		}
	}
	cout << -1 << '\n';
}