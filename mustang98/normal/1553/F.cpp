#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

int f[max_n];

int sum(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1) {
        result += f[r];
    }
    return result;
}

void inc(int i, int delta)
{
    for (; i < max_n; i = (i | (i+1))) {
        f[i] += delta;
    }
}

int sum(int l, int r) {
    int ans = sum(r);
    if (l) ans -= sum(l - 1);
    return ans;
}

int m[max_n];


template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T sum[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        f[v] = 0;
        if (l == r) {
            sum[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            sum[2 * v] += f[v] * (mid - l + 1);
            sum[2 * v + 1] += f[v] * (r - mid);
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            sum[v] += value * (r - l + 1);
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

segment_tree<ll> st;
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    ll ans = 0;
    ll sum_all = 0;
    for (int step = 0; step < n; ++step) {
        //cout << step << endl;//' ' << sum(6, 7) << ' ' << st.get_sum(1, 0, max_n - 1, 2, 2) << endl;
        int cur = m[step];
        ans += sum_all;
        for (int i = 0; i < max_n; i += cur) {
            int r = min(max_n - 1, i + cur - 1);
            //if (i < 30) cout << "$ " << i << ' ' << r << ' ' << sum(i, r) << endl;
            ans -= 1LL * i * sum(i, r);
        }
        //cout << "$$ " << ans << endl;
        ans += 1LL * cur * step;
        //cout << "% " << st.get_sum(1, 0, max_n - 1, cur, cur) << endl;
        ans -= st.get_sum(1, 0, max_n - 1, cur, cur);
        for (int i = 0; i < max_n; i += cur) {
            int r = min(max_n - 1, i + cur - 1);
            st.update(1, 0, max_n - 1, i, r, i);
        }
        sum_all += cur;
        inc(cur, 1);
        //cout << "ANS " << ans << endl;
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}