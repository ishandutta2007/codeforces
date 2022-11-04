#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#include <unordered_set>

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int MOD = 1000000007;

const int N = 2222222;

int not_prime[N];
int last_prime[N];

LL pow_mod(LL x, int y) {
    LL z = 1;
    for (; y; y >>= 1) {
        if (y & 1) z = z * x % MOD;
        x = x * x % MOD;
    }
    return z;
}

bool cmp_l(const pair<PII, int>& a, const pair<PII, int>& b) {
    return a.first.first < b.first.first;
}

bool cmp_r(const pair<PII, int>& a, const pair<PII, int>& b) {
    return a.first.second < b.first.second;
}

LL phi(LL x, int y) {
    return (x - 1) * pow_mod(x, y - 1) % MOD;
}

int current[N];

LL delta[N * 4];
LL prod[N * 4];

void build(int left, int right, int x) {
    prod[x] = delta[x] = 1;
    if (left < right) {
        int mid = (left + right) >> 1;
        build(left, mid, x * 2);
        build(mid + 1, right, x * 2 + 1);
    }
}

void down(int x) {
    if (delta[x] > 1) {
        delta[x * 2] = delta[x * 2] * delta[x] % MOD;
        delta[x * 2 + 1] = delta[x * 2 + 1] * delta[x] % MOD;
        prod[x * 2] = prod[x * 2] * delta[x] % MOD;
        prod[x * 2 + 1] = prod[x * 2 + 1] * delta[x] % MOD;
        delta[x] = 1;
    }
}

void mult(int left, int right, int l, int r, int x, int d) {
    if (l <= left && r >= right) {
        delta[x] = delta[x] * d % MOD;
        prod[x] = prod[x] * d % MOD;
        return;
    }
    int mid = (left + right) >> 1;
    down(x);
    if (l <= mid) mult(left, mid, l, r, x * 2, d);
    if (r > mid) mult(mid + 1, right, l, r, x * 2 + 1, d);
    prod[x] = prod[x * 2] * prod[x * 2 + 1] % MOD;
}

int get_prod(int left, int right, int at, int x) {
    if (left == right) {
        return prod[x];
    }
    int mid = (left + right) >> 1;
    down(x);
    if (at <= mid) {
        return get_prod(left, mid, at, x * 2);
    }
    return get_prod(mid + 1, right, at, x * 2 + 1);
}

int last[N];

int main(){
    for (int i = 2; i < N; ++i) {
        if (not_prime[i]) {
            continue;
        }
        last_prime[i] = i;
        for (int j = i + i; j < N; j += i) {
            not_prime[j] = 1;
            last_prime[j] = i;
        }
    }
    int n;
    cin >> n;
    VI a(n), h(n);
    REP(i, n) {
        scanf("%d", &a[i]);
    }

    int q;
    cin >> q;
    vector< pair<PII, int> > q_by_r(q);
    REP(i, q) {
        scanf("%d%d", &q_by_r[i].first.first, &q_by_r[i].first.second);
        --q_by_r[i].first.first;
        --q_by_r[i].first.second;
        q_by_r[i].second = i;
    }

    vector< pair<PII, int> > q_by_l = q_by_r;
    sort(ALL(q_by_r), cmp_r);
    sort(ALL(q_by_l), cmp_l);

    vector<LL> ans(q);
    fill(ALL(ans), 1);

    // for (int k = 2; k <= 1000; ++k) {
    //     if (not_prime[k]) continue;
    //     fill(current, current + n, 0);
    //     int ptr_l = 0, ptr_r = 0;
    //     int cnt = 0;
    //     if (k >= 100) {

    //     }
    //     for (int i = 0; i < n; ++i) {
    //         while (ptr_l < q && q_by_l[ptr_l].first.first == i) {
    //             current[q_by_l[ptr_l].second] -= cnt; 
    //             ++ptr_l;
    //         }
    //         while (a[i] % k == 0) {
    //             ++cnt;
    //             a[i] /= k;
    //         }
    //         while (ptr_r < q && q_by_r[ptr_r].first.second == i) {
    //             int delta = cnt + current[q_by_r[ptr_r].second];
    //             if (delta) {
    //                 // cout << "k is " << k << ", delta is " << delta << endl;
    //                 ans[q_by_r[ptr_r].second] = 
    //                     (ans[q_by_r[ptr_r].second] * phi(k, delta)) % MOD;
    //             }
    //             ++ptr_r;
    //         }
    //     }
    // }
    // REP(i, n) cout << a[i] << endl;

    build(0, n - 1, 1);
    FILL(last, -1);
    int ptr_r = 0;
    for (int i = 0; i < n; ++i) {
        while (a[i] > 1) {
            int p = last_prime[a[i]], q = 0, pr = 1;
            while (a[i] % p == 0) {
                ++q;
                pr *= p;
                a[i] /= p;
            }
            if (last[p] == -1) {
                mult(0, n - 1, 0, i, 1, phi(p, q));
            } else {
                mult(0, n - 1, last[p] + 1, i, 1, phi(p, q));
                mult(0, n - 1, 0, last[p], 1, pr);
            }
            last[p] = i;
        }
        while (ptr_r < q && q_by_r[ptr_r].first.second == i) {
            ans[q_by_r[ptr_r].second] = 
                (ans[q_by_r[ptr_r].second] * get_prod(0, n - 1, q_by_r[ptr_r].first.first, 1)) % MOD;
            ++ptr_r;
        }
    }

    REP(i, q) cout << ans[i] << endl;

    return 0;
}