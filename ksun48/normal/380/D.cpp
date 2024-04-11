#include<iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
LL powmod(LL a, LL b){
	if(b == 0) return 1LL;
	LL k = powmod(a, b/2);
	if(b % 2 == 0) return (k*k) % MOD;
	return (((k*k)% MOD)*a) % MOD;
}
LL fact[200000];
LL nCr(LL n, LL r){
	return (fact[n]*powmod((fact[r]*fact[n-r])%MOD,MOD-2)) % MOD;
}
int main(){
	fact[0] = 1;
	for(LL i = 1; i < 200000; i++){
		fact[i] = (fact[i-1]*i) % MOD;
	}
	LL n;
	cin >> n;
	LL seats[n];
	for(LL i = 0; i < n; i++) cin >> seats[i];
	for(LL i = 0; i < n; i++) seats[i]--;
	LL back[n];
	for(LL i = 0; i < n; i++) back[i] = -1;
	for(LL i = 0; i < n; i++) if(seats[i] >= 0) back[seats[i]] = i;
	LL num = 0;
	for(LL i = 0; i < n; i++) if(seats[i] >= 0) num++;
	if(num == 0){
		cout << powmod(2LL, n-1) << endl;
		return 0;
	}
	LL seat = -1;
	for(LL i = 0; i < n; i++){
		if(back[i] >= 0){
			seat = i;
			break;
		}
	}
	LL left, right;
	LL ans = 0;
	if(back[seat]-seat >= 0){
		left = back[seat]-seat;
		right = back[seat];
		LL curans = 1;
		if(seat > 0) curans *= powmod(2, seat-1);
		for(LL i = seat+1; i < n; i++){
			if(back[i] >= 0){
				if(back[i] >= left && back[i] <= right){
					curans = 0;
					break;
				}
				if(back[i] < left){
					if(back[i] + i >= n){
						curans = 0;
						break;
					}
					if(back[i] + i < right){
						curans = 0;
						break;
					}
					curans = (curans * nCr(i+left-right-1, left-back[i]-1)) % MOD;
					left = back[i];
					right = back[i]+i;
				} else if(back[i] > right){
					if(back[i] - i < 0){
						curans = 0;
						break;
					}
					if(back[i] - i > left){
						curans = 0;
						break;
					}
					curans = (curans * nCr(i+left-right-1, back[i]-right-1)) % MOD;
					left = back[i]-i;
					right = back[i];
				}
			}
		}
		curans = (curans * nCr(n-right+left-1, left)) % MOD;
		ans = (ans+curans) % MOD;


	}
	if(back[seat]+seat < n && (seat > 0)){
		left = back[seat];
		right = back[seat]+seat;
		LL curans = 1;
		if(seat > 0) curans *= powmod(2, seat-1);
		for(LL i = seat+1; i < n; i++){
			if(back[i] >= 0){
				if(back[i] >= left && back[i] <= right){
					curans = 0;
					break;
				}
				if(back[i] < left){
					if(back[i] + i >= n){
						curans = 0;
						break;
					}
					if(back[i] + i < right){
						curans = 0;
						break;
					}
					curans = (curans * nCr(i+left-right-1, left-back[i]-1)) % MOD;
					left = back[i];
					right = back[i]+i;
				} else if(back[i] > right){
					if(back[i] - i < 0){
						curans = 0;
						break;
					}
					if(back[i] - i > left){
						curans = 0;
						break;
					}
					curans = (curans * nCr(i+left-right-1, back[i]-right-1)) % MOD;
					left = back[i]-i;
					right = back[i];
				}
			}
		}
		curans = (curans * nCr(n-right+left-1, left)) % MOD;
		ans = (ans+curans) % MOD;
	}
	cout << ans << endl;
	return 0;
}