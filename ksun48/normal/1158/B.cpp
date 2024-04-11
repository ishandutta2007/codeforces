#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	int m = (n - k) / 2 + 1;
	for(int i = 0; i < n; i++){
		if((i + 1) % m == 0){
			cout << '1';
		} else {
			cout << '0';
		}
	}
	cout << '\n';
}