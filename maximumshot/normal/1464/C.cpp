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

const int LOG = 60;

bool fast(int n, ll T, string s) {
    T -= 1ll << (s[n - 1] - 'a');
    T += 1ll << (s[n - 2] - 'a');
    vector<ll> have(LOG);
    for (int i = 0; i + 2 < n; i++) {
        T -= 1ll << (s[i] - 'a');
        have[s[i] - 'a' + 1]++;
    }
    if (T > 0)
        return false;
    T = -T;
    for (int j = LOG - 1; j >= 0; j--) {
        ll add = 1ll << j;
        while (T >= add && have[j] > 0)
            T -= add, have[j]--;
    }
    return T == 0;
}

void work() {
    int n;
    ll T;
    cin >> n >> T;
    string s;
    cin >> s;
    bool fs = fast(n, T, s);
    cout << (fs ? "Yes" : "No") << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}