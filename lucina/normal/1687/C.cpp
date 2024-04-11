#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;
int64_t sum[nax];
vector <int> t[nax];
array <int, 2> c[nax];
vector <int> wait_q[nax];
vector <int> link_l[nax];
vector <int> link_r[nax];
bool used[nax];
queue <int> bfs_q;
bool del[nax];

int nxt[nax];
int get_nxt(int x) {
    return nxt[x] == x ? x : nxt[x] = get_nxt(nxt[x]);
}
void turn_off(int x) {
    nxt[x] = x + 1;
}


bool solve() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> sum[i];

    for (int i = 1, x ; i <= n ; ++ i) {
        cin >> x;
        sum[i] += sum[i - 1] - x;
    }

    for (int i = 1 ; i <= m ; ++ i) {
        auto &[l, r] = c[i];
        cin >> l >> r;
        link_r[l - 1].push_back(i);
        link_l[r].push_back(i);
        if (sum[r] == sum[l - 1] && sum[r] == 0) {
            bfs_q.push(i);
        } else if (sum[r] == 0) {
            wait_q[l - 1].push_back(i);
        } else if (sum[l - 1] == 0) {
            wait_q[r].push_back(i);
        }
        used[i] = false;
    }

    iota(nxt + 1, nxt + n + 2, 1);
    fill(del, del + 1 + n, false);

    for (int i = 1 ; i <= n ; ++ i) {
        if (sum[i] == 0) nxt[i] = i + 1, del[i] = true;
    }


    while (!bfs_q.empty()) {
        int u = bfs_q.front(); bfs_q.pop();
        auto &[l, r] = c[u];
        static vector <int> iter; iter.clear();
        for (int j = l ; j <= r ; ++ j) {
            int nxt_j = get_nxt(j);
            if (nxt_j != j) j = nxt_j;
            if (j > r) break;
            iter.push_back(j);
            assert(!del[j]);
        }
        for (int pos : iter) {
            for (int id : link_l[pos]) {
                if (!del[c[id][0] - 1]) wait_q[c[id][0] - 1].push_back(id);
            }
            for (int id : link_r[pos]) {
                if (!del[c[id][1]]) wait_q[c[id][1]].push_back(id);
            }
        }

        for (int pos : iter) {
            for (int t : wait_q[pos]) {
                if (!used[t])
                    bfs_q.push(t), used[t] = true;;
            }
            nxt[pos] = pos + 1;
            del[pos] = true;
        }
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (get_nxt(i) == i) return false;
    }
    return true;



}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
        for (int i = 0 ; i <= n ; ++ i) {
            t[i].clear();
            link_r[i].clear();
            link_l[i].clear();
            wait_q[i].clear();
        }
    }
}
/**
    Yay Div.1~ GL
    Lucina
*/

/**

consider this test case.
1
7 5
4 4 10 9 2 7 6
9 9 8 1 6 8 1
1 6
3 4
4 5
3 4
5 7

it's not necessary to apply operation from increasing [l]

0 -5 -10 -8 0 -4 -5 0

Well .......... hard?

Look at the first non-zero position

0 -5 -10 -8 0 -4 -5 0

It's true that we must find zeros
0 -5 .......... 0
but there is no zeros as active position
what to do?


0 0 0 0 0 x ? ? ? ? ? x |
0 0 0 0 0 x x x x x x x | -> useless
Conclusion : Those numbers which sum is not zero is pointless to do operation
So In the end, it's "ZERO-BFS!!!!!"
Very simple indeed....
*/