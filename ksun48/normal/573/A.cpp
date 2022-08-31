#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		while(a[i] % 2 == 0){
			a[i] /= 2;
		}
		while(a[i] % 3 == 0){
			a[i] /= 3;
		}
		if(i > 0){
			if(a[i] != a[i-1]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;

}