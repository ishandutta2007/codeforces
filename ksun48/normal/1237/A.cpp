#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int b = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0){
			cout << a[i] / 2 << '\n';
		} else {
			int c = (a[i] - 1) / 2;
			if(b){
				c++;
			}
			b ^= 1;
			cout << c << '\n';
		}
	}
}