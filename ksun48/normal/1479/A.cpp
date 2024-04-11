#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	auto query = [&](int i){
		cout << "? " << i << '\n';
		cout << flush;
		int a;
		cin >> a;
		return a;
	};
	auto done = [&](int i){
		cout << "! " << i << '\n';
		cout << flush;
		exit(0);
	};
	int l = 0;
	int m = 1;
	int r = n+1;
	while(l + 2 < r){
		int m1, m2;
		if(m-l > r-m){
			m1 = (l+m)/2;
			m2 = m;
		} else {
			m1 = m;
			m2 = (m+r)/2;
		}
		int a1 = query(m1);
		int a2 = query(m2);
		if(a1 > a2){
			l = m1;
			m = m2;
		} else {
			r = m2;
			m = m1;
		}
	}
	done(l+1);
}