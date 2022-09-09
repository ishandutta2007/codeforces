#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 100000 + 10;

ll ans = 0;
char a[N], b[N];
int n, s[2];
int A, B;

int main() {
	read(n);
	scanf("%s %s", a + 1, b + 1);
	for(int i = 1; i <= n; i++) {
		if(a[i] == '0') s[0]++;
		else s[1]++;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == '0' && b[i] == '0') A++;
		if(a[i] == '1' && b[i] == '0') B++;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == '0') {
			if(b[i] == '0') {
				ans += s[1];
			}
		}
		if(a[i] == '1') {
			if(b[i] == '0') {
				ans += s[0];
			}
		}
	}
	cout << ans - (ll)A * (ll)B << endl;
	return 0;
}