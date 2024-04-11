#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int pos = min_element(s.begin(), s.end()) - s.begin();
        cout << s[pos] << " ";
        for (int i = 0; i < (int) s.size(); i++) {
            if (i != pos)
                cout << s[i];
        }
        cout << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}