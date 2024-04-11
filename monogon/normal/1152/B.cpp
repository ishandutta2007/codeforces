
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int x;
vector<int> v;

int main() {
	cin >> x;
//	int m = 0;
	bool b = false;
	while(x > 1) {
//		m++;
		int n = 1;
		int i = 1;
		for(; n < x; i++) {
			n = (1 << i) - 1;
		}
		v.push_back(i - 1);
		if((x ^ n) + 1 == x) {
			x ^= n;
			b = true;
			break;
		}else {
			x ^= n;
			x++;
		}
//		if(m < 10) {
//			cout << x << " " << (i - 1) << endl;
//		}
	}
	if(b) {
		cout << (2 * v.size() - 1) << endl;
	}else {
		cout << 2 * v.size() << endl;
	}
	for(unsigned int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}