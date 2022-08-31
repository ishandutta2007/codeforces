#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	int r = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		r += a[i];
	}
	for(int i = 0; i < q; i++){
		int t, x;
		cin >> t >> x;
		x--;
		if(t == 1){
			r -= a[x];
			a[x] ^= 1;
			r += a[x];
		} else if(t == 2){
			if(x < r){
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
		}
	}
}