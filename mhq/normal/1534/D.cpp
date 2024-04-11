#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2002;
bool has[maxN][maxN];
int n;
vector<int> ask(int x) {
    cout << "? " << x << endl;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (d[i] == 1) {
            has[x][i] = has[i][x] = true;
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    auto dst = ask(1);
    int c0 = 0;
    int c1 = 0;
    for (int i = 1; i <= n; i++) {
        if (dst[i] % 2 == 0) c0++;
        else c1++;
    }
    if (c0 - 1 <= c1) {
        for (int i = 2; i <= n; i++) {
            if (dst[i] % 2 == 0) ask(i);
        }
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (dst[i] % 2 == 1) ask(i);
        }
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (has[i][j]) cout << i << " " << j << endl;
        }
    }
    return 0;
}