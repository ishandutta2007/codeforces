#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, t, k, d;
	cin >> n >> t >> k >> d;
	LL cur = t * ((n+k-1)/k);
	cur--;
	LL f = (cur / t) * k + (max(cur-d,0LL)/t)*k;
	if(f >= n){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}