
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n;
int x[1000];
int y[1000];

multiset<pair<int, int> > s;
set<tuple<int, int, int> > s2;

int gcd(int a, int b) {
	int r;
	do {
		r = a % b;
		a = b;
		b = r;
	}while(r != 0);
	return a;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			// slope of line
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			if(dx < 0) {
				dx = -dx; dy = -dy;
			}
			// distance from line to origin, so we ignore duplicate lines
			long long dist;
			if(dx == 0) {
				dy = 1;
				dist = x[i];
			}else if(dy == 0) {
				dx = 1;
				dist = y[i];
			}else {
				int d = gcd(dx, abs(dy));
				dx /= d;
				dy /= d;
				dist = dy * x[i] - dx * y[i];
			}
			auto t = make_tuple(dx, dy, dist);
			if(s2.find(t) == s2.end()) {
				s.insert(make_pair(dx, dy));
				s2.insert(make_tuple(dx, dy, dist));
			}
		}
	}
	long long count = 0;
	long long pairs = s2.size() * (s2.size() - 1) / 2;
	while(!s.empty()) {
		int size1 = s.size();
		s.erase(*s.begin());
		long long dsize = size1 - s.size();
		count += (dsize * (dsize - 1)) / 2;
	}
	cout << (pairs - count) << endl;
}