#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	if(n & 1){
		cout << "YES" << '\n';
		for(int b = 0; b < 2; b++){
			for(int i = 0; i < n; i++){
				if((i & 1) == b){
					cout << 2*i+1 << ' ';
				} else {
					cout << 2*i+2 << ' ';
				}
			}
		}
		cout << '\n';
	} else {
		cout << "NO" << '\n';
	}
}