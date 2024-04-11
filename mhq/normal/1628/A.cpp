#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(n + 5);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int ptr = 0;
        int sz = n;
        vector<int> b;
        while (ptr < sz) {
            int cur_mx = 0;
            while (cnt[cur_mx]) cur_mx++;
            vector<bool> hv(cur_mx);
            int need = cur_mx;
            int nptr = ptr;
            while (nptr < sz) {
                if (a[nptr] < cur_mx) {
                    need -= !hv[a[nptr]];
                    hv[a[nptr]] = true;
                }
                nptr++;
                if (need == 0) break;
            }
            assert(need == 0);
            for (int j = ptr; j < nptr; j++) {
                cnt[a[j]]--;
            }
            ptr = nptr;
            b.push_back(cur_mx);
        }
        cout << b.size() << '\n';
        for (int v : b) cout << v << " ";
        cout << '\n';
    }
    return 0;
}