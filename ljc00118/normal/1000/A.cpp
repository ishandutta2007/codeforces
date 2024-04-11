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

map <string, int> f1, f2;

const int N = 105;

int n, ans;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string a;
		cin >> a;
		f1[a]++;
	}
	for(int i = 1; i <= n; i++) {
		string a;
		cin >> a;
		f2[a]++;
	}
	ans = n;
	for(map <string, int> :: iterator it = f1.begin(); it != f1.end(); it++) ans -= min(f1[it -> first], f2[it -> first]);
	cout << ans << endl;
	return 0;
}