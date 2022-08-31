#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

vector<int> v[max_n];
ll ans[max_n];

pair<map<int, int>*, int> rec(int cur, int pr) {
    //cout << "#" << cur << endl;
    if (v[cur].size() == 1 && pr != -1) {
        map<int, int>* mp = new map<int, int>();
        (*mp)[0] = 1;
        ans[cur] = 0;
        return {mp, 1};
    }
    vector<pair<map<int, int>*, int>> vr;
    pair<map<int, int>*, int> best = MP(nullptr, 0);
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == pr) continue;
        pair<map<int, int>*, int> nx = rec(to, cur);
        //cout << "$" << cur << endl;
        if (best.F == nullptr) {
            best = nx;
            ans[cur] = ans[to] - (best.S - 1);
        } else if (best.first->size() < nx.F->size()) {
            vr.PB(best);
            best = nx;
            ans[cur] = ans[to] - (best.S - 1);
        }else {
            vr.PB(nx);
        }
    }
    //cout << "lol" << endl;
    int dept = best.S;
    //cout << cur << ' ' << best.S << endl;
    ll bestval = (*best.F)[ans[cur]];
    for (int i = 0; i < vr.size(); ++i) {
        map<int, int>* mp = vr[i].F;
        int d = vr[i].S;
        for (auto it : *mp) {
            int dep = it.F + d;
            int val = it.S;
            (*best.F)[dep - dept] += val;
            if ((*best.F)[dep - dept] > bestval) {
                bestval = (*best.F)[dep - dept];
                ans[cur] = dep - dept;
            }
            if ((*best.F)[dep - dept] == bestval && ans[cur] > (dep - dept)) {
                bestval = (*best.F)[dep - dept];
                ans[cur] = dep - dept;
            }
        }
    }
    //cout << dept << endl;
    ans[cur] += dept;
    if (bestval == 1) {
        ans[cur] = 0;
    }
    (*best.first)[-dept] = 1;
    best.second++;
    return best;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        v[b].PB(a);
        v[a].PB(b);
    }
    rec(0, -1);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}