#include <iostream>
using namespace std;
typedef long long int LL;

int main(){
	LL n; cin >> n;
	if(n == 2) {cout << 1 << endl; return 0;}
	n -= 3;
	int i = 2; LL a = 1, b = 2, c;
	for(; n >= b; ++ i)
		n -= b, c = a + b, a = b, b = c;
	cout << i << endl;
}