#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; bool fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 300000 + 10;

ll a[N], b[N];
ll s[6][N];
ll n, ans, S = 0;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++) read(b[i]);
	for(int i = 1; i <= n; i++) {
		s[0][i] = s[0][i - 1] + a[i];
		s[1][i] = s[1][i - 1] + b[i];
		s[2][i] = s[2][i - 1] + a[i] * i;
		s[3][i] = s[3][i - 1] + b[i] * i;
		S += (a[i] + b[i]);
	}
	for(int i = n; i >= 1; i--) {
		s[4][i] = s[4][i + 1] + a[i] * (n - i + 1);
		s[5][i] = s[5][i + 1] + b[i] * (n - i + 1);
	}
	ans = s[2][n] + s[5][1] + s[1][n] * n;
	bool now = 0; ll sum = 0;
	for(int i = 1; i <= n; i++) {
		if(now == 0) {
			sum += (i * 2 - 1) * a[i];
			sum += (i * 2) * b[i];
		}
		else {
			sum += (i * 2 - 1) * b[i];
			sum += (i * 2) * a[i];
		}
		now = !now;
		ll tmp = sum;
		if(now == 0) {
			tmp += s[2][n] - s[2][i];
			tmp += (s[0][n] - s[0][i]) * i;
			tmp += s[5][i + 1] - s[5][n + 1];
			tmp += (s[1][n] - s[1][i]) * (n + i);
		}
		else {
			tmp += s[3][n] - s[3][i];
			tmp += (s[1][n] - s[1][i]) * i;
			tmp += s[4][i + 1] - s[4][n + 1];
			tmp += (s[0][n] - s[0][i]) * (n + i); 
		}
		ans = max(ans, tmp);
	}
	cout << ans - S << endl;
	return 0;
}