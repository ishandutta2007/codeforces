#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 10;
const int B = 20;

struct query_t {
    int l, r, id;

    void read(int _id) {
        id = _id;
        scanf("%d %d", &l, &r);
    }

    friend bool operator <(const query_t &a, const query_t &b) {
        if (a.l / B != b.l / B) return a.l / B < b.l / B;
        return a.r > b.r;
    }
}q[nax];
int n, nq, k;
int64_t ans[nax];
int t[nax];
int64_t sum[nax];
int64_t com[nax * 4];
int64_t ct[nax * 4];
int a[nax];
int self_id[nax];
int sub_k_id[nax];
int add_k_id[nax];
int m;
/**
    what do we need?
    we have to support four things
    -- l, ++ l , --r, ++ r;
    by adding (--l or ++ r)
    --l you are looking at numbers of sum[l - 1] + k
    on the right
    just add it to the answer.
    ++ r is the same you are looking at sum[r + 1] - k on the left
    after this add counting

    what about ++l and -- r
    it's the same looking at sum[l] + k in the right
    or looking at sum[r] - k in the left
    after this subtract count

    [l1  l2  l3  l4   l5  l6]

    again you have to take care of [l - 1, ...., r] to be correct....

*/

int get_id(int64_t x) {
    return lower_bound(com + 1, com + 1 + m, x) - com;
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", t + i);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        if (t[i] == 2) a[i] = -a[i];
        sum[i] = sum[i - 1] + a[i];
        com[++ m] = sum[i] + k;
        com[++ m] = sum[i] - k;
        com[++ m] = sum[i];
    }
    com[++ m] = sum[0];
    com[++ m] = sum[0] + k;
    com[++ m] = sum[0] - k;

    sort(com + 1, com + 1 + m);
    m = unique(com + 1, com + m + 1) - com - 1;

    for (int i = 0 ; i <= n ; ++ i) {
        self_id[i] = get_id(sum[i]);
        sub_k_id[i] = get_id(sum[i] - k);
        add_k_id[i] = get_id(sum[i] + k);
    }

    scanf("%d", &nq);

    for (int i = 1 ; i <= nq ; ++ i) {
        q[i].read(i);
    }
    sort(q + 1, q + nq + 1);
    int l = 0, r = 1;
    int64_t cur = 0;

    if (a[1] == k) cur = 1;
    ct[self_id[1]] += 1;
    ct[self_id[0]] += 1;

    for (int i = 1 ; i <= nq ; ++ i) {
        auto [el, er, id] = q[i];

        while (l >= el) {
            -- l;
            int to = add_k_id[l];
            cur += ct[to];
            ct[self_id[l]] += 1;
        }

        while (r < er) {
            ++ r;
            int from = sub_k_id[r];
            cur +=  ct[from];
            ct[self_id[r]] += 1;
        }

        while (l < el - 1) {
            int to = add_k_id[l];
            ct[self_id[l]] -= 1;
            cur -= ct[to];
            ++ l;
        }

        while (r > er) {
            int from = sub_k_id[r];
            ct[self_id[r]] -= 1;
            cur -= ct[from];
            -- r;
        }

        ans[id] = cur;
    }

    for (int i = 1 ; i <= nq ; ++ i) {
        printf("%lld\n", ans[i]);
    }
}