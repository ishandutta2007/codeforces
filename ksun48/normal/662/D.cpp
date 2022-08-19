#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int c[n];
	int d[n];
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		int k = 0;
		int r = 0;
		for(int b = 0; b < a.size(); b++){
			if(a[b] >= '0' && a[b] <= '9'){
				k *= 10;
				k += a[b]-'0';
				r++;
			}
		}
		c[i] = r;
		d[i] = k;
	}
	for(int i = 0; i < n; i++){
		int r = c[i];
		int k = d[i];
		if(r == 1){
			if(k >= 9){
				cout << 1980 + k << endl;
			} else {
				cout << 1990 + k << endl;
			}
		} else if(r == 2){
			if(k >= 99){
				cout << 1900 + k << endl;
			} else {
				cout << 2000+k << endl;
			}
		} else if(r == 3){
			if(k >= 99){
				cout << 2000 + k << endl;
			} else {
				cout << 3000 + k << endl;
			}
		} else if(r == 4){
			if(k >= 3099){
				cout << k << endl;
			} else {
				cout << 10000 + k << endl;
			}
		} else if(r == 5){
			if(k >= 13099){
				cout << k << endl;
			} else {
				cout << 100000 + k << endl;
			}
		} else if(r == 6){
			if(k >= 113099){
				cout << k << endl;
			} else {
				cout << 1000000 + k << endl;
			}
		}  else if(r == 7){
			if(k >= 1113099){
				cout << k << endl;
			} else {
				cout << 10000000 + k << endl;
			}
		}  else if(r == 8){
			if(k >= 11113099){
				cout << k << endl;
			} else {
				cout << 100000000 + k << endl;
			}
		}  else if(r == 9){
			if(k >= 111113099){
				cout << k << endl;
			} else {
				cout << 1000000000 + k << endl;
			}
		}
	}

}