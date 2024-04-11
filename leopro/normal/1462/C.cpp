#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int power(int base, int exp) {return (exp ? base * power(base, exp - 1) : 1); }
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> n;
		if(n > 45){
			cout << -1 << "\n";
		}
		else{
			int m = n;
			int k = 0, p = 0;
			string s = "";
			for(int j = 9; j >= 1; j--){
				if(m < j){
					continue;
				}
				else{
					m -= j;
					k += j * power(10, p);
					p++;
				}
			}
			cout << k << "\n";
		}
	}
	return 0;
}