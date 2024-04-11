
#include <iostream>
#include <set>

using namespace std;

int n;
long long a[200000], b[200000];
multiset<pair<long long, long long> > s;

long long gcd(long long a, long long b) {
	long long r;
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
		cin >> a[i];
	}
	int count = 0;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		if(a[i] == 0) {
			if(b[i] == 0) {
				count++;
			}
		}else if(b[i] == 0) {
			s.insert(make_pair(1, 0));
		}else {
			long long d = gcd(abs(a[i]), abs(b[i]));
			a[i] /= d;
			b[i] /= d;
			if(a[i] < 0) {
				a[i] = -a[i];
				b[i] = -b[i];
			}
			s.insert(make_pair(a[i], b[i]));
		}
	}
	int maxblock = 0;
	while(!s.empty()) {
		int s1 = s.size();
		s.erase(*s.begin());
		int s2 = s.size();
		if(s1 - s2 > maxblock) {
			maxblock = s1 - s2;
		}
	}
	cout << (maxblock + count) << endl;
}