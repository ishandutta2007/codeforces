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
    int n, q;
    cin >> n >> q;
    set<int> s;
    multiset<int> dist;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int prv = -1;
    for (int v : s) {
        if (prv != -1) {
//            cout << " ADD " << v - prv << endl;
            dist.insert(v - prv);
        }
        prv = v;
    }
    auto calc =[&]{
        if (s.size() <= 1) return 0;
        return (*(--s.end()) - *s.begin()) - (*(--dist.end()));
    };
    cout << calc() << '\n';
    while (q--) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 0) {
            s.erase(x);
            auto it = s.lower_bound(x);
            if (it != s.end()) dist.erase(dist.find(*it - x));
            if (it != s.begin()) {
                --it;
                dist.erase(dist.find(x - *it));
            }

            it = s.lower_bound(x);
            if (it != s.end() && it != s.begin()) {
                int val = *it;
                --it;
                dist.insert(val - *it);
            }

        }
        else {
            auto it = s.lower_bound(x);
            if (it != s.end() && it != s.begin()) {
                int val = *it;
                --it;
                dist.erase(dist.find(val - *it));
            }
            it = s.lower_bound(x);
            if (it != s.end()) dist.insert(*it - x);
            if (it != s.begin()) {
                --it;
                dist.insert(x - *it);
            }
            s.insert(x);
        }
        cout << calc() << '\n';
    }
    return 0;
}