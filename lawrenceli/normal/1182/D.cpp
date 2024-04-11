#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100100;
const int base = 1e5 + 6;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

struct Seq {
    ll h1, h2;
    int len;

    bool operator==(const Seq& s) {
        return h1 == s.h1 && h2 == s.h2 && len == s.len;
    }

    bool operator!=(const Seq& s) {
        return !(h1 == s.h1 && h2 == s.h2 && len == s.len);
    }

    Seq addval(int val) {
        Seq s_new = Seq();
        s_new.h1 = (h1 * base + val) % mod1;
        s_new.h2 = (h2 * base + val) % mod2;
        s_new.len = len + 1;
        return s_new;
    }
};

int n;
vector<int> adj[maxn];
int deg[maxn];
Seq dp[maxn];
bool good[maxn];

void dfs1(int cur, int par = -1) {
    // special case for leaves
    
    deg[cur] = adj[cur].size();
    
    dp[cur] = Seq();
    dp[cur].h1 = dp[cur].h2 = dp[cur].len = 0;
    dp[cur] = dp[cur].addval(deg[cur]);

    bool got_child = false;

    good[cur] = true;
    for (int i : adj[cur]) {
        if (i == par) continue;

        dfs1(i, cur);

        Seq chd_seq = dp[i].addval(deg[cur]);

        if (!got_child) {
            dp[cur] = chd_seq;
            got_child = true;
        } else {
            if (dp[cur] != chd_seq) {
                // mismatch
                good[cur] = false;
            }
        }

        good[cur] &= good[i];
    }
}

void dfs2(int cur, int par, Seq seq) {
    seq = seq.addval(deg[cur]);

    if (good[cur] && (par == -1 || adj[cur].size() == 1 || dp[cur] == seq)) {
        // found a solution
        printf("%d\n", cur);
        exit(0);
    }

    if (par == -1) {
        assert(adj[cur].size() == 1);

        int chd = adj[cur][0];
        dfs2(chd, cur, seq);
    } else {
        vector<int> bad_chd = vector<int>();
        for (int i : adj[cur]) {
            if (i == par) continue;
            Seq chd_seq = dp[i].addval(deg[cur]);
            //printf("%d %d %d\n", i, seq.h1, chd_seq.h1);
            if (chd_seq != seq || !good[i]) {
                bad_chd.push_back(i);
            }
        }

        //printf("%d %d\n", cur, bad_chd.size());
        if (bad_chd.size() > 1) {
            // more than 1 bad child, can't continue
            return;
        } else if (bad_chd.size() == 1) {
            // we can only continue on the one bad child
            dfs2(bad_chd[0], cur, seq);
        } else {
            // no bad children, we can continue on all of them
            for (int i : adj[cur]) {
                if (i == par) continue;
                dfs2(i, cur, seq);
            }
        }

    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int dfs_start = -1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            dfs_start = i;
            break;
        }
    }

    if (dfs_start == -1) {
        assert(n == 1);
        printf("1\n");
        return 0;
    }

    //printf("%d\n", dfs_start);

    dfs1(dfs_start);
    if (good[dfs_start]) {
        printf("%d\n", dfs_start);
        return 0;
    }
    Seq start_seq = Seq();
    start_seq.h1 = start_seq.h2 = start_seq.len = 0;
    dfs2(dfs_start, -1, start_seq);

    printf("-1\n");
    return 0;
}