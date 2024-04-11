#include <bits/stdc++.h>

#define MP make_pair
#define F first
#define S second

using namespace std;

int ans[3][3];

int main() {
    int k;
    cin >> k;
    int ones = 0;
    int nk = 0;
    for (int i = 0; i <= 17; ++i) {
        ones |= (1 << i);
    }
    nk = (ones ^ k);
    cout << 3 << ' ' << 3 << endl;
    cout << ones << ' ' << nk << ' ' << 0 << endl;
    cout << k << ' ' << ones << ' ' << k << endl;
    cout << 0 << ' ' << k << ' ' << k << endl;
    return 0;
}