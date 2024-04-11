#include <bits/stdc++.h>

using namespace std;

const int K = 42;

const int N = 100 * 1000 + 10;
int g[K][K];

void pre() {
    for (int i = 1; i < K; i++)
        for (int j = 1; j < K; j++)
            g[i][j] = __gcd(i, j);
}

struct Item {
    int pos;
    int mod;
    int idx;

    Item(int pos, int mod, int idx): pos(pos), mod(mod), idx(idx) {}
};

struct Checker {
    vector<int> pos;
    vector<int> cnt;

    Checker() {
        clear();
    }
    
    void clear() {
        pos.assign(K, 0);
        cnt.assign(K, 0);
    }

    void remove(const Item& item) {
        assert(cnt[item.mod]);
        cnt[item.mod]--;
    }

    bool add(const Item& item) {
        if (cnt[item.mod] && pos[item.mod] != item.pos)
            return false;
        for (int mod = 1; mod < K; mod++)
            if (cnt[mod] && (pos[mod] - item.pos) % g[mod][item.mod])
                return false;
        pos[item.mod] = item.pos;
        cnt[item.mod]++;
        return true;
    }
};

int calc(const vector<Item>& items) {
    int res = 0;
    Checker checker;
    for (int l = 0, r = 0; l < items.size();) {
        for (; r < items.size(); r++) {
            if (items[r].idx - items[l].idx != r - l)
                break;
            if (!checker.add(items[r]))
                break;
        } 
        res = max(res, r - l);
        if (items[r].idx - items[l].idx != r - l) { 
            l = r;
            checker.clear();
        } else {
            checker.remove(items[l]);
            l++;
        }
    }
    return res;
}

vector<Item> at[N];

int main() {
    ios_base::sync_with_stdio(0);
    pre();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            at[x].push_back(Item(j, k, i));
        }
    }
    for (int i = 1; i <= m; i++)
        cout << calc(at[i]) << "\n";        
    return 0;
}