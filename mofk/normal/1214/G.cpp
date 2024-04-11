#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, q;
bitset <2001> pref[2001];
bitset <2001> row[2001];
int cnt[2001];
set <pair <int, int> > ord;
bool ok[2001];
set <int> good;
 
bool check(int x, int y) {
    return (row[x] & row[y]) != row[x];
}
 
void del(int id) {
    auto it = ord.find({cnt[id], id});
    auto lt = it, rt = it;
    ++rt;
    if (it != ord.begin()) --lt;
    if (it != ord.begin()) {
        if (ok[lt->second]) ok[lt->second] = 0, good.erase(lt->second);
    }
    if (rt != ord.end()) {
        if (ok[it->second]) ok[it->second] = 0, good.erase(it->second);
    }
    if (it != ord.begin() && rt != ord.end()) {
        if (check(lt->second, rt->second))
            ok[lt->second] = 1, good.insert(lt->second);
    }
    ord.erase(it);
}
 
void add(int id) {
    ord.insert({cnt[id], id});
    auto it = ord.find({cnt[id], id});
    auto lt = it, rt = it;
    ++rt;
    if (it != ord.begin()) --lt;
    if (it != ord.begin() && rt != ord.end()) {
        if (ok[lt->second]) ok[lt->second] = 0, good.erase(lt->second);
    }
    if (it != ord.begin()) {
        if (!ok[lt->second] && check(lt->second, it->second))
            ok[lt->second] = 1, good.insert(lt->second);
    }
    if (rt != ord.end()) {
        if (!ok[it->second] && check(it->second, rt->second))
            ok[it->second] = 1, good.insert(it->second);
    }
}
 
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) ord.insert({0, i});
    for (int i = 1; i <= m; ++i) {
        pref[i] = pref[i-1];
        pref[i].set(i);
    }
    while (q--) {
        int id, l, r;
        cin >> id >> l >> r;
        del(id);
        row[id] ^= pref[r] ^ pref[l-1];
        cnt[id] = row[id].count();
        add(id);
 
        if (good.empty()) cout << -1 << endl;
        else {
            int x = *good.begin();
            auto it = ord.find({cnt[x], x});
            auto rt = it; ++rt;
            int y = rt->second;
            if (x > y) swap(x, y);
            bitset <2001> bs = row[x] & row[y];
            int u = (row[x] ^ bs)._Find_first();
            int v = (row[y] ^ bs)._Find_first();
            if (u > v) swap(u, v);
            cout << x << ' ' << u << ' ' << y << ' ' << v << endl;
        }
    }
    return 0;
}