#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int main(void) {
    int x; string s, t;
    cin >> x >> s >> t;
    if (t[0] == 'w') {
        cout << (x == 5 || x == 6) + 52 << endl;
    }
    else {
        if (x <= 29) cout << 12 << endl;
        else if (x == 30) cout << 11 << endl;
        else cout << 7 << endl;
    }
    return 0;
}