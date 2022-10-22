#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

double M[N];
int n;
int a[N];
int Right[N];
int fen[N];
ll pref_right[N];
ll pref_pref_right[N];
int Left[N];
int Min[N];
ll LeftSum[N];
ll func[N];

void add(int pos, int val) {
    for(int cur = pos;cur <= n;cur |= (cur + 1))
        fen[cur] += val;
}

int get(int pos) {
    int res = 0;
    for(int cur = pos;cur > 0;cur = (cur & (cur + 1)) - 1)
        res += fen[cur];
    return res;
}

int get(int l, int r) {
    if(l > r) return 0;
    else return get(r) - get(l - 1);
}

int min_fen[N];
ll sum_fen[N];

void add_min(int pos, int val) {
    for(int cur = n - pos + 1;cur <= n;cur |= (cur + 1)) {
        min_fen[cur] = min( min_fen[cur], val );
    }
}

int get_min(int value) {
    // > value
    int res = inf;
    for(int cur = n - (value + 1) + 1;cur > 0;cur = (cur & (cur + 1)) - 1) {
        res = min(res, min_fen[cur]);
    }
    return res;
}

void add_sum(int pos, int val) {
    for(int cur = pos;cur <= n;cur |= (cur + 1)) {
        sum_fen[cur] += val;
    }
}

ll get_sum_my(int pos) {
    ll res = 0;
    for(int cur = pos;cur > 0;cur = (cur & (cur + 1)) - 1)
        res += sum_fen[cur];
    return res;
}

ll get_sum(int value) {
    return get_sum_my(n) - get_sum_my(value);
}

int main() {

    for(int i = 0;i < N;i++) {
        min_fen[i] = inf;
    }

    M[1] = 0.0;

    for(int i = 2;i < N;i++) {
        M[i] = M[i - 1] + (i - 1) / 2.0;
    }

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    double COEF = 1ll * n * (n + 1) / 2;

    double result = 0.0;

    for(int k = 1;k <= n;k++) {
        result += M[k] * double(n - k + 1) / COEF;
    }

    for(int i = n;i >= 1;i--) {
        Right[i] = get(1, a[i] - 1);
        add(a[i], 1);
    }

    for(int i = 0;i < N;i++) fen[i] = 0;

    for(int i = 1;i <= n;i++) {
        Left[i] = get(a[i] + 1, n);
        Min[i] = get_min(a[i]);
        LeftSum[i] = get_sum(a[i]);
        add(a[i], 1);
        add_sum(a[i], i);
        add_min(a[i], i);
        func[i] = LeftSum[i];
    }

    for(int i = 1;i <= n;i++) {
        pref_right[i] = pref_right[i - 1] + Right[i];
    }

    for(int i = 1;i <= n;i++) {
        pref_pref_right[i] = pref_pref_right[i - 1] + pref_right[i];
    }

    ll current = 0;

    for(int r = 1;r <= n;r++) {
        current += 1ll * Right[r] * r - func[r];
        result += (pref_pref_right[r - 1] + (pref_right[n] - pref_right[r]) * r + current) / COEF;
    }

    printf("%.15lf\n", result);

    return 0;
}