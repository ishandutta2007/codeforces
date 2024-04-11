
#include <iostream>

using namespace std;

int n, m, h, a[100], b[100], c, M[100][100];

int main() {
	cin >> n >> m >> h;
	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> c;
			M[i][j] = c == 1 ? min(b[i], a[j]) : 0;
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
}