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

    int n, m, k;
    cin >> n >> m >> k;

    string res;

    for (int i = 1; i < n; i++)
        res.push_back('U');
    for (int j = 1; j < m; j++)
        res.push_back('L');

    int i = 0, j = 0;

    while (1) {
        if (i % 2 == 0) {
            if (j + 1 < m)
                res.push_back('R'), j++;
            else if (i + 1 < n) {
                res.push_back('D');
                i++;
            } else {
                break;
            }
        } else {
            if (j > 0)
                res.push_back('L'), j--;
            else if (i + 1 < n) {
                res.push_back('D');
                i++;
            } else {
                break;
            }
        }
    }

    cout << (int) res.size() << "\n";
    cout << res << "\n";

    return 0;
}