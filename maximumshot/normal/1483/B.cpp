#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

struct DSU {
    vector<int> a;
    vector<int> link, del;
    set<int> alive;
    int n = 0;
    int cnt = 0;

    DSU(const vector<int>& a): a(a) {
        n = (int) a.size();
        link.resize(n);
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (gcd(a[i], a[j]) > 1)
                link[i] = j;
            else
                link[i] = i;
            if (link[i] == i)
                cnt++;
            alive.insert(i);
        }
    }

    int get_next_alive(int j) {
        auto fnd = alive.upper_bound(j);
        if (fnd != alive.end())
            return *fnd;
        else
            return *alive.begin();
    }

    bool finish() {
        return cnt == 0 || alive.empty();
    }

    int find(int i) {
        return i == link[i] ? i : link[i] = find(link[i]);
    }

    void set_link(int pos, int value) {
        if (link[pos] == pos)
            cnt--;
        link[pos] = value;
        if (link[pos] == pos)
            cnt++;
    }

    int jump(int i) {
        int j = find(i);
        int k = get_next_alive(j);
        if (k == j) {
            cnt = 0;
            if (a[k] == 1)
                del.push_back(k);
            alive.clear();
            return -1;
        }
        int t = get_next_alive(k);
        set_link(k, k);
        alive.erase(k);
        if (link[k] == k)
            cnt--;
        del.push_back(k);
        if (gcd(a[j], a[t]) > 1)
            set_link(j, t);
        return t;
    }

    vector<int> get_deleted() {
        return del;
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        DSU dsu(a);
        for (int i = 0; i != -1;) {
            if (dsu.finish())
                break;
            i = dsu.jump(i);
        }
        vector<int> res = dsu.get_deleted();
        cout << (int) res.size() << " ";
        for (auto x : res)
            cout << x + 1 << " ";
        cout << "\n";
    }

    return 0;
}