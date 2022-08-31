#include<iostream>
using namespace std;
typedef long long LL;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		if(i > 0) cout << 'R';
		for(int j = 0; j < a[i]; j++){
			cout << 'P';
			if(j<a[i]-1){
				if(i>0){
					cout << 'L' << 'R';
				} else {
					cout << 'R' << 'L';
				}
			}
		}
	}
	cout << endl;
}