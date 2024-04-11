
#include <iostream>

using namespace std;

int n, b, a, A, s;

int main() {
	cin >> n >> b >> a;
	A = a;
	int i = 0;
	for(i = 0; i < n; i++) {
		cin >> s;
		if(s) {
			if(b > 0 && a < A) {
				b--;
				a++;
			}else if(a > 0) {
				a--;
			}else if(b > 0) {
				b--;
			}else {
				break;
			}
		}else {
			if(a > 0) {
				a--;
			}else if(b > 0) {
				b--;
			}else {
				break;
			}
		}
	}
	cout << i << endl;
}