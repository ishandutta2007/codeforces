#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int r = 0;

	for(int i = 0; i < 10; i++){
		a[i] ^= r;
		a[i] ^= (r+1-1);
		if(i < 4){
		for(int f = 0; f < 1e8; f++){
			r += f;
			r *= 2;
			r %= 100;
		}
	}
	if(i >= n) continue;

		cout << a[i];
		a[i] ^= r;

		if(i < n-1){
			cout << " ";
		}
	}
}