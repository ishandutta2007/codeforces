#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

vector<int> x, y;

int main()
{
    //freopen("input.txt", "r", stdin);
    int ans = 0;
    x.PB(0);
    y.PB(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (x.back() == a && y.back() == b) continue;
        x.PB(a);
        y.PB(b);
    }
    if (x.size() == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i < x.size(); ++i) {
        int x1 = x[i - 1];
        int x2 = x[i];
        int y1 = y[i - 1];
        int y2 = y[i];
        int a = max(x1, y1);
        int b = min(x2, y2);
        if (b >= a) {
            ans += (b - a + 1);
        }
        if (x2 == y2) --ans;
    }
    if (x.back() == y.back()) {
        ++ans;
    }
    cout << ans;

    return 0;
}