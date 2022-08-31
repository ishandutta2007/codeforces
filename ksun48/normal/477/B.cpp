#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, k;
	cin >> n >> k;
	cout << (6*n-1)*k << endl;
	for(LL i = 0; i < n; i++){
		cout << k*(6*i+1) << " " << k*(6*i+2) << " " << k*(6*i+3) << " " << k*(6*i+5) << endl;
	}

}