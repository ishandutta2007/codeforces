#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 1000 * 1000 + 10;
const int N = 200 * 1000 + 10;
const int B = 400;

int cnt[MAX_A];
long long curSum;
int a[N];

inline void add(int x) {
    curSum += (2 * cnt[x] + 1ll) * x;
    cnt[x]++;
}

inline void remove(int x) {
    cnt[x]--;
    curSum -= (2 * cnt[x] + 1ll) * x;
}

struct Query {
    int L;
    int R;
    int id;
    
    Query(int L, int R, int id): L(L), R(R), id(id) {}
    
    bool operator<(const Query& q) const {
        return R < q.R;
    }
};

vector<Query> at[N / B + 10];
long long ans[N];
int block[N];

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < N; i++) {
        block[i] = i / B;
    }
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        at[l / B].push_back(Query(l, r, i));
    }
    for (int i = 0; i < N / B; i++) {
        sort(at[i].begin(), at[i].end());
    }
    for (int b = 0; b < n / B + 1; b++) {
        int last = b * B + B;
        memset(cnt, 0, sizeof(cnt));
        curSum = 0;
        for (Query cur : at[b]) {
            while (last <= cur.R) {
                add(a[last]);
                last++;
            }
            for (int i = cur.L; block[i] == block[cur.L] && i <= cur.R; i++) {
                add(a[i]);
            }
            ans[cur.id] = curSum;
            for (int i = cur.L; block[i] == block[cur.L] && i <= cur.R; i++) {
                remove(a[i]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}