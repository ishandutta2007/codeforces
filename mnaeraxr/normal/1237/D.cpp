#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(3 * n);

    int m = oo, M = 0;

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        m = min(m, v);
        M = max(M, v);
        a[i] = a[i + n] = a[i + 2 * n] = 2 * v;
    }

    if (2 * m >= M){
        for (int i = 0; i < n; ++i)
            cout << -1 << " ";
        cout << endl;
        return 0;
    }


    vector<int> ans(n);
    vector<pii> inc(1, pii(0, 3 * n));

    int cur = oo;

    for (int i = 3 * n - 1; i >= 0; --i){
        while (inc.back().first >= a[i])
            inc.pop_back();

        inc.push_back(pii(a[i], i));

        int p = lower_bound(inc.begin(), inc.end(), pii(a[i] / 2, 0)) - inc.begin() - 1;
        int pos = inc[p].second;

        cur = min(cur + 1, pos - i);
        if (i < n)
            ans[i] = cur;
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}