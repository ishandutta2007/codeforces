#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	set<int> visit;
	while(visit.find(n) == visit.end()) {
		visit.insert(n);
		++n;
		while(n % 10 == 0) n /= 10;
	}
	cout << visit.size() << '\n';
}