#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, k;
	cin >> n >> k;
	n++;
	LL stuff[n];
	for(LL i = 0; i < n; i++){
		cin >> stuff[i];
	}
	LL a = 0;
	LL i;
	for(i = n-1; i >= 0; i--){
		a *= 2;
		a += stuff[i];
		if(a > k || a < -k){
			break;
		}
	}
	if(i == -1) i = 0;
	LL b = 0;
	LL ans = 0;
	for(LL j = 0; j < i; j++){
		b += stuff[j];
		if(b % 2 != 0){
			cout << 0 << endl;
			return 0;
		}
		b /= 2;
	}
	a += b;
	for(LL j = i; j < n; j++){
		LL r = stuff[j]-a;
		if(r <= k && r >= -k && (j < (n-1) || r != 0)) ans++;
		if(a%2 != 0){
			break;
		}
		a /= 2;
	}
	cout << ans << endl;
}