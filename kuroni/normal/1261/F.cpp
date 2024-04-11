#include <bits/stdc++.h>
using namespace std;
    
const int MOD = 998244353, LG = 60;
    
int n, cnt = 0;
long long ret = 0, l, r, pr;
vector<long long> eve;
long long pw[LG];

struct segment {
    long long pre;
    int bit;
    
    segment(long long _pre = 0, int _bit = 0) : pre(_pre), bit(_bit) {
        pre &= ((1LL << (LG - bit)) - 1) << bit;
    }
    
    segment operator^(const segment &oth) const {
        return segment(pre ^ oth.pre, max(bit, oth.bit));
    }
    
    bool contains(const segment &oth) const {
        return pre + (1LL << bit) >= oth.pre + (1LL << oth.bit);
    }
};
vector<segment> buc[LG];
vector<vector<segment>> a, b;

struct trie {
    trie *bit[2];
    bool fin;
    
    trie(bool _fin = false) : fin(_fin) {
        bit[0] = bit[1] = nullptr;
    }
} *rt = new trie();

void push(long long l, long long r, vector<vector<segment>> &ve) {
    ve.push_back({});
    for (; l + (l & -l) <= r; l += l & -l) {
        ve.back().push_back(segment(l, __lg(l & -l)));
    }
    reverse(ve.back().begin(), ve.back().end());
    ve.push_back({});
    for (; r - (r & -r) >= l; r -= r & -r) {
        ve.back().push_back(segment(r - 1, __lg(r & -r)));
    }
    reverse(ve.back().begin(), ve.back().end());
}

void init(vector<vector<segment>> &ve) {
    eve.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        eve.push_back(l);
        eve.push_back(-r - 1);
    }
    sort(eve.begin(), eve.end(), [](const long long &u, const long long &v) {
        return abs(u) < abs(v) || (abs(u) == abs(v) && u > v);
    });
    for (long long &v : eve) {
        if (cnt == 0) {
            pr = v;
        }
        cnt += abs(v) / v;
        if (cnt == 0) {
            push(pr, -v, ve);
        }
    }
}

void add(segment u) {
    trie *cur = rt;
    for (int i = LG - 1; i >= u.bit; i--) {
        int b = u.pre >> i & 1;
        if (cur->bit[b] != nullptr && cur->bit[b]->fin) {
            return;
        }
        if (cur->bit[b] == nullptr) {
            cur->bit[b] = new trie();
        }
        cur = cur->bit[b];
    }
    cur->fin = true;
    (ret += u.pre % MOD * pw[u.bit]) %= MOD;
    if (u.bit > 0) {
        (ret += (pw[u.bit] - 1) * pw[u.bit - 1]) %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pw[0] = 1;
    for (int i = 1; i < LG; i++) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
    init(a);
    init(b);
    for (vector<segment> &u : a) {
        for (vector<segment> &v : b) {
            for (int i = 0, j = 0; i < u.size() && j < v.size(); ) {
                if (u[i].bit > v[j].bit) {
                    buc[u[i].bit].push_back(u[i] ^ v[j]);
                    buc[u[i].bit].push_back(u[i] ^ v.back());
                    i++;
                } else {
                    buc[v[j].bit].push_back(u[i] ^ v[j]);
                    buc[v[j].bit].push_back(u.back() ^ v[j]);
                    j++;
                }
            }
        }
    }
    for (int i = LG - 1; i >= 0; i--) {
        for (segment &v : buc[i]) {
            add(v);
        }
    }
    cout << (ret + MOD) % MOD;
}