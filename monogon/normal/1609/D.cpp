
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct dsu {
    vector<int> a;
    dsu(int n) : a(n, -1) {}
    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    int size(int x) {
        return -a[find(x)];
    }
    bool join(int x, int y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    dsu D(n + 1);
    int groups = 1;
    multiset<int> small, big;
    rep(i, 1, n) {
        small.insert(1);
    }
    int ans = 1;
    big.insert(1);
    rep(i, 1, d + 1) {
        int x, y;
        cin >> x >> y;
        if(D.find(x) == D.find(y)) {
            groups++;
        }else {
            int s1 = D.size(x);
            int s2 = D.size(y);
            
            if(big.count(s1) > 0) {
                big.erase(big.find(s1));
                ans -= s1;
            }else {
                small.erase(small.find(s1));
            }
            
            if(big.count(s2) > 0) {
                big.erase(big.find(s2));
                ans -= s2;
            }else {
                small.erase(small.find(s2));
            }
            D.join(x, y);
            if(D.size(x) > *big.begin()) {
                big.insert(D.size(x));
                ans += D.size(x);
            }
            else small.insert(D.size(x));
        }
        while(sz(big) < groups) {
            ans += *prev(small.end());
            big.insert(*prev(small.end()));
            small.erase(prev(small.end()));
        }
        while(sz(big) > groups) {
            ans -= *big.begin();
            small.insert(*big.begin());
            big.erase(big.begin());
        }
        cout << ans - 1 << '\n';
    }
}