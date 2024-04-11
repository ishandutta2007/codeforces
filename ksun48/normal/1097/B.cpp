#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < (1<<n); i++){
		int num = 0;
		for(int b = 0; b < n; b++){
			if((1<<b) & i){
				num += a[b];
			} else {
				num -= a[b];
			}
		}
		if(num % 360 == 0){
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
	return 0;
}