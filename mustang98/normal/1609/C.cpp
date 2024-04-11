#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

int m[max_n];
int nxt1[max_n];

bool is_sost[max_n];
void init() {
    is_sost[1] = true;
    for (int i = 2; i * i < max_n; ++i) {
        if (is_sost[i]) continue;
        for (int j = i * i; j < max_n; j += i) {
            is_sost[j] = true;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    init();
    while(t--) {
        int n, e;
        cin >> n >> e;

        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a == 1) m[i] = 1;
            else if (is_sost[a]) m[i] = 0;
            else m[i] = 2;
        }
        for (int i = n; i < 2 * n; ++i) {
            m[i] = 0;
        }
        ll ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (m[i + e] != 1) {
                nxt1[i] = i + e;
            } else {
                nxt1[i] = nxt1[i + e];
            }
            if (m[i] == 0) continue;
            if (m[i] == 1) {
                int x = nxt1[i];
                if (m[x] == 0) continue;
                int y = nxt1[x];
                ans += (y - x) / e;
            } else {
                int x = nxt1[i];
                ans += (x - i) / e - 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}