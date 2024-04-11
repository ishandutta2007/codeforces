#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	LL a = 0;
	LL b = 0;
	cin >> n;
	while(a*b < n){
		if(a <= b){
			a++;
		} else {
			b++;
		}
	}
	cout << 2*(a+b) << endl;
}