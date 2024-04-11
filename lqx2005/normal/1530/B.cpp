#include <bits/stdc++.h>

using namespace std;
int T;

int main() {
	cin >> T;
	for(; T--; ) {
		int h, w;
		cin >> h >> w;
		for(int i = 1; i <= w; i++) {
			cout << "01"[i & 1];
		}
		cout << endl;
		for(int i = 2; i <= h - 2; i++) {
			cout << "01"[i & 1];
			for(int j = 2; j < w; j++) cout << "0";
			cout << "01"[i & 1];
			cout << endl;
		}
		for(int i = 1; i <= w; i++) cout << "0";
		cout << endl;
		for(int i = 1; i <= w; i++) {
			cout << "01"[i & 1];
		}
		cout << endl;
		
	}
	return 0;
}