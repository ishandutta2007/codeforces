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

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();

        int res = 0;
        int ca = 0;
        int pref = 0;
        for (char c : s) {
            if (c == 'A')
                ca++;
            else {
                if (ca > 0)
                    ca--;
                else
                    pref++;
            }
        }

        cout << pref % 2 + ca << "\n";
    }

    return 0;
}