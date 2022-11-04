#include <bits/stdc++.h>
using namespace std;

int a[3];

long long go (int x){
	return (long long)(x + 2LL) * (x + 1LL) / 2LL;
}

int main(){
	cin >> a[0] >> a[1] >> a[2];
	int l; cin >> l;
	long long res = 0;
	for (int i=0; i<=l; i++){
		res += go(i);
		int maxi = (a[0] + a[1] + a[2] + i + 1)/2;
		for (int j=0; j<3; j++){
			int need = max(0, maxi-a[j]);
			if (i < need)
				continue;
			res -= go(i-need);
		}
	}
	cout << res << endl;
	return 0;
}