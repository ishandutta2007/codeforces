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

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map <int, int> cnt;
    for (int i = 0; i < m; i++) cnt[i] = n / m;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i] % m;
        map <int, int> :: iterator it = cnt.upper_bound(x - 1);
        if (it == cnt.end())
            it = cnt.begin(), x -= m;
        res += it -> first - x;
        a[i] += it -> first - x;
        if (--it -> second == 0) cnt.erase(it);
    }
    cout << res << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}