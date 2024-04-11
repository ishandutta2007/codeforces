#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 2 * (int)1e5;
int as[N];
int bs[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		as[v-1] = i+1;
	}
	
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		int j = as[v-1];
		if (mx >= j) {
			cout << "0 ";
		} else {
			cout << j-mx << ' ';
			mx = j;
		}
	}
	cout << '\n';
}