#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL h1, h2;
	cin >> h1 >> h2;
	LL a, b;
	cin >> a >> b;
	for(LL i = 1; i <= 100000; i++){
		h1 += 8*a;
		if(h1 >= h2){
			cout << i-1 << endl;
			return 0;
		}
		h1 -= 12*b;
		h1 += 4*a;
		if(h1 >= h2){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}