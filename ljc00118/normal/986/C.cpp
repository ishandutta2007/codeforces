#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
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

const int bit = 23, N = 1 << bit;

bool vis[N], hav[N];
int a[N];
int n, m, ans, cnt;

void dfs(int now) {
	if(vis[now]) return; vis[now] = 1;
	if(hav[cnt ^ now]) dfs(cnt ^ now);
	for(int i = 0; i < n; i++) if(!(now & (1 << i))) dfs(now ^ (1 << i));
}

int main() {
	cin >> n >> m; cnt = (1 << n) - 1;
	for(int i = 1; i <= m; i++) read(a[i]), hav[a[i]] = 1;
	for(int i = 1; i <= m; i++) {if(!vis[cnt ^ a[i]]) {ans++; dfs(a[i]);}}
	cout << ans << endl;
	return 0;
}