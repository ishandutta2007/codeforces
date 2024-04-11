#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;
const int LOG = 60;

int n;
ll b[N];
int f[N];
int cnt[LOG];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        for (int j = 0; j < LOG; j++) {
            if ((1ll << j) & b[i]) {
                f[i] = j;
                break;
            }
        }
        cnt[f[i]]++;
    }

    int best = max_element(cnt, cnt + LOG) - cnt;

    cout << n - cnt[best] << "\n";

    for (int i = 1; i <= n; i++) {
        if (f[i] != best) {
            cout << b[i] << " ";
        }
    }

    cout << "\n";

    return 0;
}