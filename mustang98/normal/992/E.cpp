#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_sqrt = 2011, inf = 1000111222;

int arr[max_n];
ll sum[max_n];
ll N, q;

ll m1[max_n];
ll m2[max_n];
int p1, p2;

ll m[max_n];

bool my_cmp(int i, int j) {
    return m[i] < m[j];
}

struct sqrt_dec {
    int ind[max_n];
    ll to_add[max_sqrt] = {0};
    int bl_cnt, bl_sz;
    int n;
    vector<int> perm;

    sqrt_dec(int n) {
        this->n = n;
        bl_sz = int(sqrt(n));
        if (n > 50000) {
            bl_sz = 500;
        }
        bl_cnt = n / bl_sz;
        if (n % bl_sz) bl_cnt++;
        for (int i = 0; i < n; ++i) {
            m[i] = sum[i];
            ind[i] = i;
        }
        for (int bl = 0; bl < bl_cnt; ++bl) {
            int from = bl * bl_sz;
            int to = min(from + bl_sz, n);
            sort(ind + from, ind + to, my_cmp);
            sort(m + from, m + to);
            perm.PB(bl);
        }
        random_shuffle(perm.begin(), perm.end());
    }

    void add(int pos, int val) {
        int bl = pos / bl_sz;
        int from = bl * bl_sz;
        int to = min(from + bl_sz, n);
        int p;
        for (p = from; p < to; ++p) {
            if (ind[p] == pos) break;
        }
        m[p] += val;
        while (p + 1 < to && m[p] > m[p + 1]) {
            swap(m[p], m[p + 1]);
            swap(ind[p], ind[p + 1]);
            ++p;
        }
        while (p > from && m[p] < m[p - 1]) {
            swap(m[p], m[p - 1]);
            swap(ind[p], ind[p - 1]);
            --p;
        }
    }

    void add_suff(int start, int val) {
        int bl = start / bl_sz;
        p1 = 0, p2 = 0;
        int from = bl * bl_sz;
        int to = min(from + bl_sz, n);
        for (int i = from; i < to; ++i) {
            if (ind[i] >= start) {
                m2[p2] = m[i] + val;
                m2[p2 + 1] = ind[i];
                p2 += 2;
            } else {
                m1[p1] = m[i];
                m1[p1 + 1] = ind[i];
                p1 += 2;
            }
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i < (to - from); ++i) {
            if (c1 == p1) {
                m[from + i] = m2[c2];
                ind[from + i] = m2[c2 + 1];
                c2 += 2;
            } else if (c2 == p2) {
                m[from + i] = m1[c1];
                ind[from + i] = m1[c1 + 1];
                c1 += 2;
            } else if (m1[c1] <= m2[c2]) {
                m[from + i] = m1[c1];
                ind[from + i] = m1[c1 + 1];
                c1 += 2;
            } else {
                m[from + i] = m2[c2];
                ind[from + i] = m2[c2 + 1];
                c2 += 2;
            }
        }
        ++bl;
        for(;bl < bl_cnt; ++bl) {
            to_add[bl] += val;
        }
    }
    int find0() {
        int from = 0;
        for (int bl_i = 0; bl_i < bl_cnt; ++bl_i) {
            int bl = bl_i; //perm[bl_i];
            from = bl * bl_sz;
            int to = from + bl_sz;
            if (bl + 1 == bl_cnt) to = n;
            ll val = -to_add[bl];
            ll* it = lower_bound(m + from, m + to, val);
            if (it != m + to && *it == val) {
                return ind[from + (it - (m + from))];
            }
            from += bl_sz;
        }
        return -1;
    }

};

int main()
{
    //freopen("input.txt", "r", stdin);
    /*int M;
    cin >> M;
    cout << M << endl;
    cout << (200000 / M) << endl;
    cout << (200000 / M) * log2(M) << endl;
    return 0;*/
    srand(time(0));
    cin >> N >> q;
    ll cur_s = 0;
    for (int i = 0; i < N; ++i) {
        arr[i] = (i == 0 ? 1 : 0);
        scanf("%d", arr + i);
        sum[i] = arr[i] - cur_s;
        cur_s += arr[i];
    }
    sqrt_dec sd(N);
    vector<int> ans;
    for (int i = 0; i < q; ++i) {
        int ind;
        int st;
        ind = 2, st = 0;
        scanf("%d %d", &ind, &st);
        --ind;
        ll add_v = st - arr[ind];
        arr[ind] = st;
        sd.add(ind, add_v);
        if (ind != N - 1) {
            sd.add_suff(ind + 1, -add_v);
        }
        int in = sd.find0();
        if (in == -1) {
            ans.PB(-1);
        } else {
            ans.PB(in + 1);
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}