#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

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

    string color = "blue";
    int x = 0;

    while (n--) {
        string s;
        cin >> s;
        if (s == "lock") x = 1;
        else if (s == "unlock") x = 0;
        else {
            if (!x)
                color = s;
        }
    }

    cout << color << "\n";

    return 0;
}