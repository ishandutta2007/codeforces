#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int n, nq, s, D;
int a[nax];

priority_queue <pair <int, int>, vector <pair <int, int>>, greater<>> pq;
set <int> stones;
set <int> jump;
int dis[nax];
int remap[nax * 5];
/// practice implementation again


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> nq >> s >> D;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        stones.insert(a[i]);
        remap[a[i]] = i;
    }

    /** now try some priority search
     at every step for all possible jumps(already reachable stones)
        updated distance to its neighbor in both direction
    */
    pq.emplace(0, s);
    memset(dis, -1, sizeof(dis));

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        // cout << "D V " << d << " " << v << '\n';
        pq.pop();
        assert(d >= 0);
        if (dis[v] >= 0) continue;
        dis[v] = d;
        stones.erase(a[v]);

        for (int to : {a[v] - D, a[v] + D}) {
            jump.insert(to);
            auto it = stones.lower_bound(to);
            if (it != stones.end()) {
                pq.emplace(max(d, *it - to), remap[*it]);
            }

            if (it != stones.begin()) {
                -- it;
                pq.emplace(max(d, to - *it), remap[*it]);
            }
        }

        auto it = stones.lower_bound(a[v]);

        if (it != stones.end()) {
            ///  JUMP -> STONE -> NEW_STONE
            auto j = jump.upper_bound(a[v]);
            if (j != jump.begin()) {
                -- j;
                pq.emplace(max(d, *it - *j), remap[*it]);
            }
        }

        if (it != stones.begin()) {
            -- it;
            ///  NEW_STONE <-- STONE <-- JUMP
            auto j = jump.lower_bound(a[v]);
            if (j != jump.end()) {
                pq.emplace(max(d, *j - *it), remap[*it]);
            }
        }
    }
/*
    for (int i = 1 ; i <= n ; ++ i)
       cout << dis[i] << " ";
    cout << '\n';
     return 0;*/
    while (nq --) {
        int i, k;
        cin >> i >> k;
        cout << (dis[i] <= k ? "Yes" : "No") << '\n';
    }

}