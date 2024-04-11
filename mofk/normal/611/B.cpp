#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int main(void) {
    ll a, b, c;
    cin >> a >> b;
    int res = 0;
    ff(i, 2, 61) ff(j, 0, i - 2) {
        c = (1ll << i) - (1ll << j) - 1;
        if (c >= a && c <= b) ++res;
    }
    cout << res << endl;
    return 0;
}