#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t, n, k;
 
	cin >> t;
 
	while(t--){
		cin >> n >> k;
 
		cout << (n / k) * k + min(k / 2, n % k) << endl;
	}
 
	return 0;
}