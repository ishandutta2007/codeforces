#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e9 + 7;

const int N = 1e5;
vector<int> conns[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll s;
	cin >> n >> s;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	// Put all weight to leaves, and put weight of leaves to be equal
	int lc = 0;
	for (int i = 0; i < n; ++i) {
		if (conns[i].size() == 1) ++lc;
	}
	cout << fixed << setprecision(10) << 2*(ld)s/lc << '\n';
}