#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, r;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> r;
        if (n <= r)
            cout << ll(n) * (n - 1) / 2 + 1 << endl;
        else cout << ll(r) * (r + 1) / 2 << endl;
    }
    return 0;
}