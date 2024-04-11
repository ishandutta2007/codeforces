#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a1 = 1;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(!a[i]) a1 = 0;
	}
	int m = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			for(int k = i; k <= j; k++){
				a[k] = 1-a[k];
			}
			int r = 0;
			for(int k = 0; k < n; k++){
				r += a[k];
			}
			m = max(m,r);
			for(int k = i; k <= j; k++){
				a[k] = 1-a[k];
			}
		}
	}
	cout << m << endl;
	return 0;
}