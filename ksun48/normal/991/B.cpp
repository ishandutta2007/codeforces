#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	cin >> n;
	vector<LL> f(n);
	for(int j = 0; j < n; j++){
		cin >> f[j];
		f[j] *= 2;
	}
	sort(f.begin(), f.end());
	LL ans = n;
	for(LL a = 0; a <= n; a++){
		LL sum = 0;
		for(int j = 0; j < n; j++){
			sum += f[j];
		}
		if(sum >= 9*n){
			ans = a;
			break;
		}
		f[a] = 10;
	}
	cout << ans << endl;
}