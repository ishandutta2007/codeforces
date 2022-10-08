
#include <iostream>
#include <set>

using namespace std;

int n, a, b, c, r;
set<int> s;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}
	switch(s.size()) {
	case 1:
		r = 0;
		break;
	case 2:
		a = *s.begin();
		b = *prev(s.end());
		if((b - a) % 2 == 0) {
			r = (b - a) / 2;
		}else {
			r = b - a;
		}
		break;
	case 3:
		a = *s.begin();
		b = *next(s.begin());
		c = *prev(s.end());
		if(c - b == b - a) {
			r = b - a;
		}else {
			r = -1;
		}
		break;
	default:
		r = -1;
	}
	cout << r << endl;
}