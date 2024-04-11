#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int n, m;

bool ch(int x) {
    int a = x/2 - x/6, b = x/3 - x/6, c = x/6;
    int aa = max(0, n - a), bb = max(0, m - b);
    return aa + bb <= c;
}

int main(void) {
    cin >> n >> m;
    int l = 1, r = 1000000000;
    while (r > l) {
        int m = l + r >> 1;
        if (ch(m)) r = m;
        else l = m + 1;
    }
    cout << l << endl;
    return 0;
}