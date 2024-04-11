
#include <iostream>

using namespace std;

int n;
string str[50];
bool b[50][50];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> str[i];
		for(int j = 0; j < n; j++) {
			b[i][j] = (str[i][j] == '.');
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(b[i][j]) {
				if(i < n - 2 && j > 0 && j < n - 1 && b[i + 1][j - 1] && b[i + 1][j] && b[i + 1][j + 1] && b[i + 2][j]) {
					b[i][j] = b[i + 1][j - 1] = b[i + 1][j] = b[i + 1][j + 1] = b[i + 2][j] = false;
				}else {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
}