#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

string s;
char c; int l, r;
string ans[2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    ans[0] = ans[1] = string(13, '.');
    ff(i, 0, 26) ff(j, i + 1, 26) if (s[i] == s[j]) c = s[i], l = i, r = j;
    if (r - l == 1) return cout << "Impossible" << endl, 0;
    int m = l; while (m - l < r - m) ++m;
    ff(i, l, m - 1) ans[0][i + 13 - m] = s[i];
    ff(i, m, r - 1) ans[1][12 + m - i] = s[i];
    int ptr = l + 13 - m, col = 0, v = -1;
    fb(i, l - 1, 0) {
        ptr += v;
        if (ptr < 0) ptr = 0, ++col, v = 1;
        ans[col][ptr] = s[i];
    }
    fb(i, 26, r + 1) {
        ptr += v;
        if (ptr < 0) ptr = 0, ++col, v = 1;
        ans[col][ptr] = s[i];
    }
    cout << ans[0] << endl << ans[1] << endl;
    return 0;
}