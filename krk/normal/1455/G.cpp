#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;

int n, s;

struct pos {
    map <int, ll> M;
    ll nil;
    multiset <ll> S;
    pos() {}
    pos(int key, ll val) {
        M.clear();
        M.insert(make_pair(key, val));
        nil = 0;
        S.clear();
        S.insert(val);
    }
    void Erase(int key) {
        auto it = M.find(key);
        if (it == M.end()) return;
        auto it2 = S.find(it->second);
        M.erase(it);
        S.erase(it2);
    }
    void Add(int key, ll val) {
        val -= nil;
        auto it = M.find(key);
        if (it != M.end() && it->second <= val) return;
        if (it != M.end()) Erase(key);
        M.insert(make_pair(key, val));
        S.insert(val);
    }
    void Set(int key, ll cost) {
        if (key == s) { nil += cost; return; }
        ll cur = *S.begin() + nil;
        Erase(key);
        nil += cost;
        Add(key, cur);
    }
    ll Get(int key) {
        auto it = M.find(key);
        if (it == M.end()) return Inf;
        return it->second + nil;
    }
    void Merge(const pos &p) {
        for (auto key_val: p.M)
            Add(key_val.first, key_val.second + p.nil);
    }
};

typedef pos* ppos;

char typ[10];
vector <ppos> S;

int main()
{
    scanf("%d %d", &n, &s);
    S.push_back(new pos(0, 0));
    for (int i = 0; i < n; i++) {
        scanf("%s", typ);
        if (typ[0] == 's') {
            int key, val; scanf("%d %d", &key, &val);
            S.back()->Set(key, val);
        } else if (typ[0] == 'i') {
            int v; scanf("%d", &v);
            ll val = S.back()->Get(v);
            S.back()->Erase(v);
            S.push_back(new pos(v, val));
        } else {
            ppos A = S.back(); S.pop_back();
            ppos B = S.back(); S.pop_back();
            if (A->M.size() < B->M.size()) swap(A, B);
            A->Merge(*B);
            S.push_back(A);
        }
    }
    ll res = *(S.back()->S.begin()) + S.back()->nil;
    cout << res << endl;
    return 0;
}