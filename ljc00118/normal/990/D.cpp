#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;

int n, a, b;

int main() {
	cin >> n >> a >> b;
	if(n == 1) {
		cout << "YES" << endl;
		cout << "0" << endl;
		return 0;
	}
	if(a != 1 && b != 1) {
		cout << "NO" << endl;
		return 0;
	}
	if(a == 1 && b == 1) {
		if(n <= 3) {
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		if(n == 4) {
			cout << "0110" << endl;
			cout << "1001" << endl;
			cout << "1000" << endl;
			cout << "0100" << endl;
			return 0;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(abs(i - j) == 1) printf("1");
				else printf("0");
			}
			printf("\n");
		}
		return 0;
	}
	cout << "YES" << endl;
	if(a == 1) {
		int tmp = n - b + 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) printf("0");
				else if(i <= tmp && j <= tmp) printf("0");
				else printf("1");
			}
			printf("\n");
		}
	}
	else {
		int tmp = n - a + 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) printf("0");
				else if(i <= tmp && j <= tmp) printf("1");
				else printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}