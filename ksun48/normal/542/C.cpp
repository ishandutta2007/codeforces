#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){
	if(a == 0) return b;
	return gcd(b%a, a);
}
LL lcm(LL a, LL b){
	return (a/gcd(a,b))*b;
}
int main(){
	LL n;
	cin >> n;
	LL f[n+1];
	for(LL i = 1; i <= n; i++){
		cin >> f[i];
	}
	LL period[n+1];
	LL first[n+1];
	for(LL i = 1; i <= n; i++){
		LL idx[n+1];
		for(LL j = 1; j <= n; j++) idx[j] = -1;
		LL cur = i;
		LL num = 0;
		idx[cur] = num;
		while(1){
			num++;
			cur = f[cur];
			if(idx[cur] >= 0){
				first[i] = idx[cur];
				period[i] = num - idx[cur];
				//cout << first[i] << " " << period[i] << endl;
				break;
			}
			idx[cur] = num;
		}
	}
	LL mf = 0;
	LL lc = 1;
	for(LL i = 1; i <= n; i++){
		mf = max(mf, first[i]);
		lc = lcm(lc, period[i]);
	}
	mf += lc-1;
	LL r = mf/lc;
	r *= lc;
	if(r == 0) r += lc;
	cout << r << endl;


}