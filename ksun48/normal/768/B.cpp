#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL sums[55];
LL v[55];

LL solve(LL q){
	LL ans = 0;
	for(int i = 0; i < 54; i++){
		LL r = (q + (1LL<<i) ) / (1LL << (i+1));
		ans += r * v[i];
		//cout << r << " " << v[i] << endl;
	}
	return ans;
}
int main(){

	LL n, l, r;
	cin >> n >> l >> r;
	vector<int> b;
	LL cur = 0;
	LL val = 0;
	int t =	0;
	for(int i = 0; i < 55; i++){
		v[i] = n % 2;
		if(n > 0) t++;
		n /= 2;
	}
	reverse(v,v+t);
	cout << solve(r) - solve(l-1) << endl;
}