#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<int> x(11);
	for(int& a : x) cin >> a;
	reverse(x.begin(), x.end());
	using ld = long double;
	cout << fixed << setprecision(2);
	for(int a : x){
		ld ans = sqrt(abs(a)) + pow(a, 3) * 5;
		cout << "f(" << a << ") = ";
		if(400 < ans){
			cout << "MAGNA NIMIS!" << '\n';
		} else {
			cout << ans << '\n';
		}
	}
}