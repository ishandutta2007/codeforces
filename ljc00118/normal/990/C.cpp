#include<bits/stdc++.h>
using namespace std;

const int N = 300000 + 10;

char s[N];
int len;
int l[N], r[N], L[N], R[N];
char c[N];
int n;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%s", c + 1);
		int tmp = strlen(c + 1);
		len = 0;
		s[1] = ' ';
		for(int j = 1; j <= tmp; j++) {
			if(s[1] == ')') {
				r[i] = -1;
				break;
			}
			if(c[j] == ')') {
				if(len == 0) {
					r[i] = -1;
					break;
				}
				len--;
			}
			else s[++len] = '(';
		}
		if(r[i] != -1) r[i] = len, R[r[i]]++;
		len = 0;
		s[1] = ' ';
		for(int j = tmp; j >= 1; j--) {
			if(s[1] == '(') {
				l[i] = -1;
				break;
			}
			if(c[j] == '(') {
				if(len == 0) {
					l[i] = -1;
					break;
				}
				len--;
			}
			else s[++len] = ')';
		}
		if(l[i] != -1) l[i] = len, L[l[i]]++;
	}
	long long ans = 0;
	//cout << L[0] << " " << R[0] << endl;
	for(int i = 0; i <= N - 10; i++) ans += (long long)L[i] * (long long)R[i];
	cout << ans << endl;
	return 0;
}