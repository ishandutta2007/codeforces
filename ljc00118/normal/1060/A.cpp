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

const int N = 105;

char c[N];
int n;

int main() {
	cin >> n;
	scanf("%s", c + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(c[i] == '8') cnt++;
	cout << min(cnt, n / 11) << endl;
	return 0;
}