#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	int d = 0;
	while((1 << (d+1)) <= n) d += 1;
	int ans = 0;
	for(int b = 0; b < d; b++){
		for(int i = 0; i < (1 << d); i++){
			if((i >> b) & 1){
				ans += 2;
			}
		}
	}
	cout << ans << '\n';
	for(int b = 0; b < d; b++){
		for(int i = 0; i < (1 << d); i++){
			if((i >> b) & 1){
				cout << i + 1 << ' ' << (i ^ (1 << b)) + 1 << '\n';
			}
		}
	}
	for(int b = 0; b < d; b++){
		for(int i = 0; i < (1 << d); i++){
			if((i >> b) & 1){
				cout << n - i << ' ' << n - (i ^ (1 << b)) << '\n';
			}
		}
	}
}