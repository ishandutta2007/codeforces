#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 5 * (int)1e5 + 10;
int n;
int x[maxN];
int tp[maxN];
const int AND = 0;
const int XOR = 1;
const int OR = 2;
int mask[25];
int val[25];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char s;
        cin >> s >> x[i];
        if (s == '|') tp[i] = OR;
        else if (s == '&') tp[i] = AND;
        else if (s == '^') tp[i] = XOR;
    }
    for (int bit = 0; bit < 10; bit++) {
        for (int s = 0; s < 2; s++) {
            int cur = s;
            for (int i = 1; i <= n; i++) {
                int other = (x[i] >> bit) & 1;
                if (tp[i] == OR) cur |= other;
                else if (tp[i] == AND) cur &= other;
                else cur ^= other;
            }
            if (cur == 1) {
                mask[bit] |= (1 << s);
            }
        }
    }
    for (int bit = 0; bit < 10; bit++) {
        if (mask[bit] == 3) {
            val[2] |= (1 << bit);
        }
        if (mask[bit] != 0) {
            val[1] |= (1 << bit);
        }
        if (mask[bit] == 1) {
            val[0] |= (1 << bit);
        }
    }
    cout << 3 << '\n';
    for (int i = 0; i < 3; i++) {
        if (i == 0) cout << "^ ";
        else if (i == 1) cout << "& ";
        else cout << "| ";
        cout << val[i] << '\n';
    }
    return 0;
}