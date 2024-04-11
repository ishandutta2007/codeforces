#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Coupon {
    int l;
    int r;
    int id;

    Coupon(int l, int r, int id): l(l), r(r), id(id) {}

    bool operator<(const Coupon& c) {
        return l < c.l;    
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n, k;
    cin >> n >> k;
    vector<Coupon> e;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        e.push_back(Coupon(l, r, i));
    }
    sort(e.begin(), e.end());
    set<pii> q;
    int ans = 0;
    int when = -1;
    for (int i = 0; i < e.size(); i++) {
        q.insert(pii(e[i].r, e[i].id));
        while (q.size() > k)
            q.erase(q.begin());
        if (q.size() == k) {
            int cur = q.begin()->first - e[i].l + 1;
            if (cur > ans) {
                ans = cur;
                when = i;
            }        
        }    
    } 
    cout << ans << endl;
    if (ans == 0) {
        for (int i = 1; i <= k; i++)
            cout << i << " ";
        cout << endl;
        return 0;
    }
    q.clear();
    for (int i = 0; i < e.size(); i++) {
        q.insert(pii(e[i].r, e[i].id));
        while (q.size() > k)
             q.erase(q.begin());  
        if (when == i) {
            for (auto kv : q)
                cout << kv.second + 1 << " ";
            cout << endl;
            return 0;            
        }
    }  
}