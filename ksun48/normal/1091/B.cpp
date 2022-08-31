#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	cin >> n;
	LL a = 0;
	LL b = 0;
	for(LL j = 0; j < 2*n; j++){
		LL x, y;
		cin >> x >> y;
		a += x;
		b += y;
	}
	a /= n;
	b /= n;
	cout << a << " " << b << endl;
}