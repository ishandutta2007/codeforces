#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(){
	cin >> n >> k;
	int lo = 1, hi = n;
	for (int i=0; i<n; i++){
		if (i%2 == 0){
			if (k==1){
				while (lo<=hi)
					cout << lo++ << ' ';
				cout << endl;
				break;
			}
			cout << lo++ << ' ';
		}else{
			if (k==1){
				while (hi>=lo){
					cout << hi-- << ' ';
				}
				cout << endl;
				break;
			}
			cout << hi-- << ' ';
		}
		k--;
	}
	return 0;
}