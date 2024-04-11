#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ios>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 300100;
const int block = 600;

int n, q, w[maxn];
vector<pii> qry[maxn];
ll ans[maxn], p[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (b >= block) {
            for (int j = a - 1; j < n; j += b)
                ans[i] += w[j];
        } else qry[b].push_back(pii(a - 1, i));
    }

    for (int i = 1; i < block; i++) {
        for (int j = 0; j < n; j++)
            p[j] = w[j] + (j - i >= 0 ? p[j - i] : 0);
        
        for (pii x : qry[i]) {
            int a = x.first, b = x.second;
            int ind = a + ((n - 1 - a) / i) * i;
            ans[b] = p[ind] - (a >= i ? p[a - i] : 0);
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}