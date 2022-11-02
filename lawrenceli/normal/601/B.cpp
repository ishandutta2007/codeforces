#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 100100;
const int inf = 1e9;

int n, q, a[maxn], x[maxn];
int stk[maxn], sze;
int lt[maxn], rt[maxn];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (i > 0) a[i] = abs(x[i] - x[i-1]);
    }
    a[0] = a[n] = inf;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        sze = 0;
        stk[sze++] = 0;

        for (int j = l+1; j <= r; j++) {
            while (a[j] > a[stk[sze-1]]) {
                rt[stk[sze-1]] = j - stk[sze-1];
                sze--;
            }

            lt[j] = sze == 1 ? j - l : j - stk[sze-1];
            stk[sze++] = j;
        }

        for (int j = 1; j < sze; j++)
            rt[stk[j]] = r + 1 - stk[j];

        ll ans = 0;
        for (int j = l+1; j <= r; j++) {
            //cout << lt[j] << ' ' << rt[j] << endl;
            ans += ll(lt[j]) * rt[j] * a[j];
        }
        cout << ans << '\n';
    }
}