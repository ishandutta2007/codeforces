#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	int n;
	cin >> n;
	int a[n];
	int r = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		r = max(r,a[i]);
	}
	cout << (a[n-1] ^ r) << endl;
}