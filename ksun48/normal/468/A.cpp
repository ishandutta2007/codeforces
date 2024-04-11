#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	if(n <= 3){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if(n % 2 == 0){
		cout << "2 * 1 = 2" << endl ;
		cout << "3 * 2 = 6" << endl;
		cout << "4 * 6 = 24" << endl;
		for(int k = 5; k < n; k+= 2){
			cout << k+1 << " - " << k << " = " << 1 << endl;
			cout << "24 * 1 = 24" << endl;
		}
	}
	if(n % 2 == 1){
		cout << "3 - 1 = 2" << endl ;
		cout << "2 * 2 = 4" << endl;
		cout << "4 * 5 = 20" << endl;
		cout << "20 + 4 = 24" << endl;
		for(int k = 6; k < n; k+= 2){
			cout << k+1 << " - " << k << " = " << 1 << endl;
			cout << "24 * 1 = 24" << endl;
		}
	}
}