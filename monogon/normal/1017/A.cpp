#include <iostream>
#include <set>

using namespace std;

int n, a, sum;
set<pair<int, int>> s;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		sum = 0;
		for(int j = 0; j < 4; j++) {
			cin >> a;
			sum += a;
		}
		s.insert(make_pair(-sum, i));
	}
	int count = 1;
	for(auto it : s) {
		if(it.second == 0) {
			cout << count << endl;
		}
		count++;
	}
}