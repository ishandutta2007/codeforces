#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 200100;

int h, m, n, d, z;
int place[MAXN];
map<int, int> ind;
vector<int> bit[MAXN];

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (!b) return a;
    return gcd(b, a%b);
}

int query(int c, int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[c][i];
    return ret;
}

void update(int c, int i, int v) {
    for (i++; i<bit[c].size(); i+=i&-i) bit[c][i] += v;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    cin >> h >> m >> n;
    d = gcd(h, m), z = h/d;
    for (int i=0; i<d; i++) {
        bit[i].resize(2*z+5, 0);
        int cur = i, cnt = 0;
        do {
            place[cur] = cnt++;
            cur = (cur+m)%h;
        } while (cur != i);
    }

    ll ans = 0;
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        if (c == '+') {
            int id, hash;
            cin >> id >> hash;
            int x = hash%d, y = place[hash];
            int lo = y, hi = y+z-1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (query(x, mid)-query(x, y-1) < mid-y+1) hi = mid;
                else lo = mid+1;
            }
            ans += lo-y;
            if (lo >= z) lo -= z;
            ind[id] = lo*d+x;
            update(x, lo, 1), update(x, lo+z, 1);
        } else {
            int id;
            cin >> id;
            int x = ind[id];
            update(x%d, x/d, -1), update(x%d, x/d+z, -1);
        }
    }
    cout << ans << '\n';
    return 0;
}