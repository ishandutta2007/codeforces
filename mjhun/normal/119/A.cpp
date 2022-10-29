#include <iostream>
using namespace std;

int mcd(int a, int b) {
	int c;
	while(b!=0) {
		c = b;
		b = a%b;
		a = c;
	}
	
	return a;
}

int main() {
	int a, b, n;
	bool p;
	cin >> a >> b >> n;
	
	p = true;
	
	while(n>0) {
		n -= mcd(n, p?a:b);
		p = !p;
	} 
	cout << (int)p << endl;
	
	return 0;
}