#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAX 500000

typedef long long ll;
typedef pair<int, int> pii;

int n;
ll a[MAX];
ll st[MAX + 1];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;

    st[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st[i + 1] = st[i] + a[i];
    }

    ll ways = 0;
    if (st[n] % 3 == 0) {
        ll lcut = st[n] / 3;
        ll rcut = lcut * 2;

        int lcuts = 0;
        for (int i = 2; i < n; i++) {
            if (st[i - 1] == lcut) {
                lcuts++;
            }
            if (st[i] == rcut) {
                ways += lcuts;
            }

//            cerr << i << "(" << st[i] << "): " << lcuts << ", " << ways << endl;
        }
    }
    cout << ways << endl;
    return 0;
}