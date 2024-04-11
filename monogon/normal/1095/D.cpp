#include <iostream>

using namespace std;

int n;
int a[(int) 2e5][2];

int main() {
	cin >> n;
	if(n == 3) {
		cout << "1 2 3" << endl;
		return 0;
	}

	for(int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		a[i][0]--;
		a[i][1]--;
	}
	int next = 0;
	for(int i = 0; i < n; i++) {
		cout << (next + 1) << " ";
		int b = a[next][0];
		int c = a[next][1];
		if(a[b][0] == c || a[b][1] == c) {
			next = b;
		}else {
			next = c;
		}
	}
}