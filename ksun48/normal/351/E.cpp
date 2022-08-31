#include <iostream>
using namespace std;
int abs(int a){
	return (a>0)?a:-a;
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		int l = 0, r = 0;
		for(int j = 0; j < i; j++){
			if(abs(a[j]) < abs(a[i])){
				l++;
			}
		}
		for(int j = i+1; j < n; j++){
			if(abs(a[j]) < abs(a[i])){
				r++;
			}
		}
		if(l <= r){
			a[i] = -abs(a[i]);
		} else {
			a[i] = abs(a[i]);
		}
	}
	int inv = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(a[j] < a[i]){
				inv++;
			}
		}
	}
	cout << inv << endl;
	return 0;
}