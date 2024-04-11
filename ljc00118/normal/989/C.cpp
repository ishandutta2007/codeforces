#include<bits/stdc++.h>
using namespace std;

const int N = 50 + 10;

int f[N][N];
int a[5];

int main() {
	memset(f, 0, sizeof(f));
	for(int i = 0; i < 4; i++) cin >> a[i];
	a[0]--, a[1]--;
	int n = 48, m = 50;
	cout << n << " " << m << endl;
	for(int i = 2; i <= 24; i += 2) {
		for(int j = 1; j <= m; j++) f[i][j] = 1;
	}
	for(int i = 25; i <= 48; i += 2) {
		for(int j = 1; j <= m; j++) {
			f[i][j] = 2;
		}
	}
	for(int i = 1; i <= 23; i += 2) {
		for(int j = 1; j <= m; j++) {
			if(j % 2 == 0) f[i][j] = 1;
			else {
				if(a[1] != 0) {
					a[1]--, f[i][j] = 2;
				}
				else if(a[2] != 0) {
					a[2]--;
					f[i][j] = 3;
				}
				else if(a[3] != 0) {
					a[3]--;
					f[i][j] = 4;
				}
				else f[i][j] = 1;
			}
		}
	}
	for(int i = 26; i <= 48; i += 2) {
		for(int j = 1; j <= m; j++) {
			if(j % 2 == 0) f[i][j] = 2;
			else {
				if(a[0] != 0) {
					a[0]--;
					f[i][j] = 1;
				}
				else f[i][j] = 2;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%c", f[i][j] + 'A' - 1);
		}
		printf("\n");
	}
	return 0;
}