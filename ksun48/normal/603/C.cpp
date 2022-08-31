#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k, r, v=0;
LL y(LL a){
	if(a == 0) return 0;
	if(a == 1) return 1;
	if(a == 2) return 0;
	if(a == 3) return 1;
	if(a == 4) return 2;
	if(a % 2 == 1) return 0;
	if(y(a/2) == 1) return 2;
	return 1;
}
LL z(LL a){
	if(k % 2 == 0){
		if(a == 0) return 0;
		if(a == 1) return 1;
		if(a == 2) return 2;
		if(a % 2 == 0) return 1;
		return 0;
	}
	return y(a);
}
int main(){
	cin >> n >> k;
	for(LL i = 0; i < n; i++){
		cin >> r;
		v ^= z(r);
	}
	if(v > 0){
		cout << "Kevin" << endl;
	} else {
		cout << "Nicky" << endl;
	}

}