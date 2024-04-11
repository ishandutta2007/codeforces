#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e13;

const int N = 1e5;
ll vals[N];

bool bins(const vector<ll>& vec, ll v) {
	int low = 0;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return vec[low] == v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i < n; i += 2) {
		cin >> vals[i];
	}

	vector<ll> squares;
	ll tmp = 1;
	while(tmp*tmp <= INF) {
		squares.push_back(tmp*tmp);
		++tmp;
	}

	bool fail = false;
	ll sum = 0;
	int j = 0;
	for (int i = 0; (! fail) && (i < n); ++i) {
		if (i % 2 == 0) {
			// sum <= x^2
			// x^2 + d = y^2
			// And we want to minimize x^2
			while((squares[j] <= sum) || ((i+1 != n) && (! bins(squares, squares[j] + vals[i+1])))) {
				++j;
				if (j >= squares.size()) {
					fail = true;
					break;
				}
			}
			vals[i] = squares[j] - sum;
			sum = squares[j];
		} else {
			sum += vals[i];
		}
	}

	if (fail) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		for (int i = 0; i < n; ++i) cout << vals[i] << ' '; cout << '\n';
	}
}