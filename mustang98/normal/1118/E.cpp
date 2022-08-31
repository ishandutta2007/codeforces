#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> l, r;

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    ll cnt = k * (k - 1);
    if (n > cnt) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= k; ++i) {
        for (int j = i + 1; j <= k; ++j) {
            l.PB(i); r.PB(j);
            l.PB(j); r.PB(i);
            if (l.size() >= n) {
                for (int k = 0; k < n; ++k) {
                    printf("%d %d\n", l[k], r[k]);
                }
                return 0;
            }
        }
    }


    return 0;
}