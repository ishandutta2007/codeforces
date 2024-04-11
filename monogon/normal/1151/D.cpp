
#include <iostream>
#include <set>

using namespace std;

int n;
long long a[100000];
long long b[100000];
set<pair<long long, int> > s;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		s.insert(make_pair(b[i] - a[i], i));
	}
	int i = 1;
	long long sum = 0;
	while(!s.empty()) {
		pair<long long, int> p = *s.begin();
		s.erase(s.begin());
		int idx = p.second;
		sum += a[idx] * (i - 1) + b[idx] * (n - i);
		i++;
	}
	cout << sum << endl;
}