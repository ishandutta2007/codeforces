#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n; cin >> n;
	int ans = 0;
	for (int i=1; true; i++){
		long long temp = n - i * (i+1LL) - i * (i-1LL)/2;
		if (temp<0) break;
		ans+= temp%3 == 0;
	}
	cout << ans << endl;
	return 0;
}