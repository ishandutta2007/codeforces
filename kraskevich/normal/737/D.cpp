#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int M = 10 * 1000 * 1000 + 3;
const int STEP = 7;

int mod_add(int x, int y) {
    x += y;
    if (x >= M)
        x -= M;
    return x;
}

struct HashTable {
    ll key[M];
    int val[M];

    HashTable() {
        fill(key, key + M, -1);    
        fill(val, val + M, -1);
    }

    int& operator[](const ll& k) {
        int pos = int(k % M);
        for (; key[pos] != -1 && key[pos] != k; pos = mod_add(pos, STEP))
            ;
        key[pos] = k;
        return val[pos];
    }        
};

const int INF = (int)1e9;
const int N = 4004;
const int K = 100;

HashTable mem;
int sum[N];

int get_sum(int l, int r) {
    int res = sum[r];
    if (l > 0)
        res -= sum[l - 1];
    return res;
}

ll get_hash(int l, int r, int k, int who) {
    ll res = l * 1ll * N * 2ll * K;
    res += r * 2ll * K;
    res += k * 2ll;
    res += who;
    return res; 
}

int go(int l, int r, int k, int who) {
    ll h = get_hash(l, r, k, who);
    if (mem[h] != -1)
        return mem[h];
    int& res = mem[h];
    if (who == 0)
        res = -INF;
    else
        res = INF;
    if (l + k - 1 > r)
        return res = 0;
    for (int d = 0; d <= 1; d++) {
        if (who == 0) {
            int new_l = l + k + d;
            int new_r = r;
            if (new_l > new_r + 1)
                continue;
            res = max(res, go(new_l, new_r, k + d, 1 - who) + get_sum(l, new_l - 1));
        } else {
            int new_r = r - k - d;
            int new_l = l;
            if (new_l > new_r + 1)
                continue;
            res = min(res, go(new_l, new_r, k + d, 1 - who) - get_sum(new_r + 1, r));
        }
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sum[i];
        if (i)
            sum[i] += sum[i - 1];
    }
    cout << go(0, n - 1, 1, 0) << endl;
}