# include <bits/stdc++.h>
using namespace std;

char s[120][120];
int main() {
	int n, m;
	int r = 0, c = 0, cnt = 0;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		for(int j = 0; j < m; ++j) if(s[i][j] == 'B') {
			r += i;
			c += j;
			cnt += 1;
		}
	}
	cout << r / cnt + 1 << ' ' << c / cnt + 1 << endl;
}