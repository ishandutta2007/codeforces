
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long a[50][50], b[50][50];

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i > 0 && (min(a[i - 1][j], b[i - 1][j]) >= min(a[i][j], b[i][j]) ||
					max(a[i - 1][j], b[i - 1][j]) >= max(a[i][j], b[i][j]))) {
				cout << "Impossible" << endl;
				return 0;
			}
			if(j > 0 && (min(a[i][j - 1], b[i][j - 1]) >= min(a[i][j], b[i][j]) ||
					max(a[i][j - 1], b[i][j - 1]) >= max(a[i][j], b[i][j]))) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
}