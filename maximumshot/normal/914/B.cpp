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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> cn;

    for (int x, i = 0; i < n; i++) {
        cin >> x;
        cn[x]++;
    }

    for (auto item : cn) {
        if (item.second % 2) {
            cout << "Conan\n";
            return 0;
        }
    }

    cout << "Agasa\n";

    return 0;
}