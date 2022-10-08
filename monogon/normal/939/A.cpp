#include <iostream>

using namespace std;

int n;
int f[5000];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> f[i];
		f[i]--;
	}
	for(int i = 0; i < n; i++) {
		if(f[f[f[i]]] == i) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}