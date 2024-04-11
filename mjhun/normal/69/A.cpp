#include <iostream>
using namespace std;

int main() {
	int i, n, x, y, z, x_sum=0, y_sum=0, z_sum=0;
	cin >> n;
	for(i = 0; i < n; i++) {
		cin >> x >> y >> z;
		x_sum += x;
		y_sum += y;
		z_sum += z;
	}
	if (x_sum || y_sum || z_sum) {
		cout << "NO" << endl; 
	} else {
		cout << "YES" << endl; 
	}
}