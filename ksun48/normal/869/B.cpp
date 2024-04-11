#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL a, b;
	cin >> a >> b;
	LL dig = 1;
	for(LL j = a+1; j <= b; j++){
		LL f = j % 10;
		dig = (dig * f) % 10;
		if(dig == 0) break;
	}
	cout << dig << endl;
}