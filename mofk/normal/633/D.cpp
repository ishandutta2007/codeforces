#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int a[1005];
map <int, int> cnt;

int calc(int x, int y) {
    if (a[x] == 0 && a[y] == 0) return cnt[0];
    if (a[x] == a[y] && abs(y - x) > 1) return -1;
    int f = a[x], g = a[y], ret = 2;
    map <int, int> wat; ++wat[f], ++wat[g];
    while (1) {
        int h = f + g;
        if (cnt.find(h) == cnt.end() || ++wat[h] > cnt[h]) return ret;
        ++ret; f = g; g = h;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ff(i, 1, N) cin >> a[i], ++cnt[a[i]];
    int ans = 0;
    sort(a + 1, a + N + 1);
    ff(i, 1, N) ff(j, 1, N) if (i != j) ans = max(ans, calc(i, j));
    cout << ans << endl;
    return 0;
}