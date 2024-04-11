
#include <iostream>

using namespace std;

int n, m, x, ci = -1, cj, xo, X;
int a[500];

int main() {
	cin >> n >> m;
	xo = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		xo ^= a[i];
		for(int j = 1; j < m; j++) {
			cin >> x;
			if(x != a[i]) {
				ci = i;
				cj = j;
				X = x;
			}
		}
	}
	if(xo > 0 || ci != -1) {
		cout << "TAK" << endl;
		for(int i = 0; i < n; i++) {
			if(xo == 0 && i == ci) {
				cout << (cj + 1) << " ";
			}else {
				cout << 1 << " ";
			}
		}
	}else {
		cout << "NIE" << endl;
	}
}