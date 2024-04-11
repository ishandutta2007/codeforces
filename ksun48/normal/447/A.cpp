#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int p, n;
	cin >> p >> n;
	set<int> v;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a %= p;
		if(v.count(a)){
			cout << i + 1 << '\n';
			return 0;
		}
		v.insert(a);
	}
	cout << -1 << '\n';
}