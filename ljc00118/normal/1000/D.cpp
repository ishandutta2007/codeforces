#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

const ll P = 998244353;
const int N = 1005;

ll f[N], v[N];
int a[N];
int n; 

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) read(a[i]);
	f[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= n; j++) v[j] = f[j];
		if(a[i] > 0 && a[i] < n) v[a[i]] += f[0], v[a[i]] %= P;
		for(int j = 0; j < n; j++) v[j] += f[j + 1], v[j] %= P;
		for(int j = 0; j <= n; j++) f[j] = v[j];
	}
	cout << ((f[0] - 1) % P + P) % P << endl;
	return 0;
}