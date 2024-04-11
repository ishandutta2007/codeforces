#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
int n;
map < pair < pair < int, int >, int >, int > mp;
const int maxN = 5005;
int c[maxN];
int asked = 0;
int ask(int i, int j, int k) {
    if (i > j) swap(i, j);
    if (i > k) swap(i, k);
    if (j > k) swap(j, k);
    if (mp.count(make_pair(make_pair(i, j), k))) {
        return mp[make_pair(make_pair(i, j), k)];
    }
    asked++;
    cout << "? " << i << " " << j << " " << k << endl;
    int ans;
    cin >> ans;
    //ans = min(c[i], min(c[j], c[k])) + max(c[i], max(c[j], c[k]));
    mp[make_pair(make_pair(i, j), k)] = ans;
    return ans;
}
int val[maxN];
int real_val[maxN];
int cur_val[maxN];
pair < int, int > find_five(vector < int > t) {
    vector < pair < int, int > > all;
    for (int i = 0; i < t.size(); i++) {
        ll sm = 0;
        for (int i1 = 0; i1 < t.size(); i1++) {
            for (int i2 = i1 + 1; i2 < t.size(); i2++) {
                for (int i3 = i2 + 1; i3 < t.size(); i3++) {
                    if (i1 == i || i2 == i || i3 == i) continue;
                    sm += ask(t[i1], t[i2], t[i3]);
                }
            }
        }
        all.push_back(make_pair(sm, t[i]));
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    return make_pair(all[0].second, all[1].second);
}
int find_min(vector < int > all) {
    int x = all[0];
    int y = all[1];
    for (int i = 2; i < all.size(); i++) {
        int t = all[i];
        if (t == x || t == y) continue;
        cur_val[t] = ask(x, y, t);
    }
    int best = all[2];
    for (int i = 2; i < all.size(); i++) {
        if (cur_val[all[i]] < cur_val[best]) {
            best = all[i];
        }
    }
    vector < int > pos = {x, y, best};
    for (int i = 2; i < all.size(); i++) {
        if (all[i] == best) continue;
        pos.push_back(all[i]);
        if (pos.size() == 5) break;
    }
    return find_five(pos).first;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    //  n = 1000;
    /*for (int i = 1; i <= n; i++) {
         cin >> c[i];
       //  c[i] = rand() % 21321;
    }*/
    vector < int > all;
    for (int i = 1; i <= n; i++) {
        all.push_back(i);
    }
    int ind1, ind2;
    if (n == 5) {
        auto t = find_five(all);
        ind1 = t.first;
        ind2 = t.second;
    }
    else {
        ind1 = find_min(all);
        // cout << ind1 << " here" << endl;
        vector<int> all2;
        for (int i = 1; i <= n; i++) {
            if (i == ind1) continue;
            all2.push_back(i);
        }
        ind2 = find_min(all2);
    }
    vector < int > without;
    for (int i = 1; i <= n; i++) {
        if (i == ind1 || i == ind2) continue;
        without.push_back(i);
    }
    for (int v : without) {
        val[v] = ask(v, ind1, ind2);
    }
    for (int i = 0; i < without.size(); i++) {
        for (int j = i + 1; j < without.size(); j++) {
            if (val[without[i]] > val[without[j]]) {
                swap(without[i], without[j]);
            }
        }
    }
    int vals = ask(without[0], without[1], without[2]);
    int c1 = (val[without[0]] + val[without[2]] - vals) / 2;
    real_val[ind1] = c1;
    for (int v : without) {
        real_val[v] = val[v] - c1;
    }
    int val_2 = ask(ind2, without[0], without[1]);
    real_val[ind2] = (val_2 - real_val[without[1]]);
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << real_val[i] << " ";
    }
    cout << endl;
    return 0;
}