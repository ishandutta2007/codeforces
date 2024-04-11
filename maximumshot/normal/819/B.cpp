#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 4e6 + 5;

int n;
int p[2*N];
int cnt[2 * N];
ll sum[2 * N];

void add(int pos, int val) {
    for(int cur = pos;cur < 2 * N;cur |= (cur + 1)) {
        cnt[cur] += val;
        sum[cur] += 1ll * val * (pos - 2 * n);
    }
}

pair< int, ll > get(int l, int r) {
    int cn = 0;
    ll sm = 0;
    for(int cur = r;cur >= 0;cur = (cur & (cur + 1)) - 1) {
        cn += cnt[cur];
        sm += sum[cur];
    }
    for(int cur = l - 1;cur >= 0;cur = (cur & (cur + 1)) - 1) {
        cn -= cnt[cur];
        sm -= sum[cur];
    }
    return make_pair(cn, sm);
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i]);
        p[i + n] = p[i];
    }

    for(int i = 1;i <= 2 * n;i++) {
        p[i] = p[i] - i;
    }

    for(int i = 1;i <= n;i++) {
//        add(0, 0, 3 * n, p[i] + 2 * n, 1);
        add(p[i] + 2 * n, 1);
    }

    ll best_val = inf64;
    int best_id = -1;
    pair< int, ll > tmp;
    ll tmp_val;

    for(int ql, qr, de = 0, l = 1, r = n;r <= 2 * n;l++, r++, de++) {
        tmp_val = 0;

        if(0 < 2 * n - de) {
//            tmp = get(0, 0, 3 * n, 0, 2 * n - de - 1);
            tmp = get(0, 2 * n - de - 1);
            tmp_val += (-tmp.second);
            tmp_val += 1ll * (-de) * tmp.first;
        }

        if(-de + 2 * n <= 3 * n) {
//            tmp = get(0, 0, 3 * n, -de + 2 * n, 3 * n);
            tmp = get(2 * n - de, 3 * n);
            tmp_val += tmp.second;
            tmp_val += 1ll * de * tmp.first;
        }

        if(best_val > tmp_val) {
            best_val = tmp_val;
            best_id = ((-de) % n + n) % n;
        }

//        add(0, 0, 3 * n, p[l] + 2 * n, -1);
        add(p[l] + 2 * n, -1);
        if(r < 2 * n) {
//            add(0, 0, 3 * n, p[r + 1] + 2 * n, 1);
            add(p[r + 1] + 2 * n, 1);
        }
    }

    cout << best_val << " " << best_id << "\n";

    return 0;
}