
#include <iostream>

using namespace std;

int n, m, r, s, b, Min, Max;

int main() {
	cin >> n >> m >> r;
	Min = 1001;
	Max = 0;
	for(int i = 0; i < n; i++) {
		cin >> s;
		Min = min(s, Min);
	}
	for(int i = 0; i < m; i++) {
		cin >> b;
		Max = max(b, Max);
	}
	cout << max(r, (r + ((r / Min) * (Max - Min)))) << endl;
}