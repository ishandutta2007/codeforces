#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, h, d;
	cin >> n >> d >> h;
	if(d > 2*h){
		cout << -1 << endl;
		return 0;
	}
	if(h == 1 && d == 1){
		if(n > 2){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= h; i++){
		cout << i << " " << i+1 << endl;
	}
	if(d > h){
		cout << 1 << " " << h+2 << endl;
		for(int i = 0; i < (d-h-1); i++){
			cout << h+2+i << " " << h+3+i << endl;
		}
		for(int i = 0; i < n-(d+1); i++){
			cout << 1 << " " << n-i << endl;
		}
	} else {
		for(int i = 0; i < (n-1-h); i++){
			cout << 2 << " " << n-i << endl;
		}
	}
}