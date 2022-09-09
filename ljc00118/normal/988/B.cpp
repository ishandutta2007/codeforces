#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

char c[N][N];
int F[N];
int len[N];
int n;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%s", c[i]);
		len[i] = strlen(c[i]);
		for(int j = 1; j < i; j++) {
			if(len[i] == len[j]) {
				bool ok = 1;
				for(int k = 0; k < len[i]; k++) {
					if(c[i][k] != c[j][k]) {
						ok = 0;
						break;
					}
				}
				if(ok) F[i]++;
			//	else cout << "=" << endl;
			}
			if(len[i] > len[j]) {
				bool ok = 0;
				for(int l = 0; l <= len[i] - len[j]; l++) {
					int r = l + len[j] - 1;
					bool OK = 1;
					for(int k = l; k <= r; k++) {
						if(c[i][k] != c[j][k - l]) {
							OK = 0;
							break;
						}
					}
					if(OK) {
						ok = 1;
						break;
					}
				}
				if(ok) F[i]++;
			//	else cout << ">" << endl;
			}
			if(len[i] < len[j]) {
				bool ok = 0;
				for(int l = 0; l <= len[j] - len[i]; l++) {
					int r = l + len[i] - 1;
					bool OK = 1;
					for(int k = l; k <= r; k++) {
						if(c[i][k - l] != c[j][k]) {
							OK = 0;
							break;
						}
					}
					if(OK) {
						ok = 1;
						break;
					}
				}
				if(ok) F[j]++;
				//else cout << "<" << endl;
			}
		}
	}
	bool ok = 1;
	for(int i = 0; i < n; i++) {
		bool OK = 0;
		for(int j = 1; j <= n; j++) {
			if(F[j] == i) {
				OK = 1;
				break;
			}
		}
		if(OK == 0) {
			ok = 0;
			break;
		} 
	}
	if(ok == 0) cout << "NO";
	else {
		cout << "YES" << endl;
		for(int i = 0; i < n; i++) {
			for(int j = 1; j <= n; j++) {
				if(F[j] == i) {
					printf("%s\n", c[j]);
					break;
				}
			}
		}
	}
	return 0;
}