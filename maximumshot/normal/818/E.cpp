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

ll gcd(ll x, ll y) {
    return x == 0 ? y : gcd(y % x, x);
}

ll lcm(ll x, ll y) {
    return (x / gcd(x, y)) * y;
}

int const N = 1e5 + 5;

int n, k;
int a[N];

inline int f(int x, int y) {
    ll val = 1ll * x * y;
    val = gcd(val, k);
    return (int)val;
}

void pushStack(pii * st, int & sz, int x) {
    if(sz == 0) {
        st[sz++] = make_pair(f(1, x), x);
    }else {
        int y = st[sz - 1].first;
        st[sz++] = make_pair(f(x, y), x);
    }
}

void popStack(pii * st, int & sz) {
    sz--;
}

int topStack(pii * st, int sz) {
    return st[sz - 1].second;
}

void pushQueue(pii * sl, pii * sr, int & s1, int & s2, int x) {
    pushStack(sr, s2, x);
}

void rebuild(pii * sl, pii * sr, int & s1, int & s2) {
    int x;
    while(s2 > 0) {
        x = topStack(sr, s2);
        popStack(sr, s2);
        pushStack(sl, s1, x);
    }
}

void popQueue(pii * sl, pii * sr, int & s1, int & s2) {
    if(s1 == 0) {
        rebuild(sl, sr, s1, s2);
    }
    if(s1 > 0) {
        popStack(sl, s1);
    }
}

int getQueue(pii * sl, pii * sr, int & s1, int & s2) {
    int x = s1 > 0 ? sl[s1 - 1].first : 1;
    int y = s2 > 0 ? sr[s2 - 1].first : 1;
    return f(x, y);
}

int getWithoutHead(pii * sl, pii * sr, int & s1, int & s2) {
    if(s1 == 0) {
        rebuild(sl, sr, s1, s2);
    }
    int res = 1;
    if(s1 > 1) {
        res = f(res, sl[s1 - 2].first);
    }
    return res;
}

pii sl[N];
pii sr[N];
int s1 = 0;
int s2 = 0;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    ll res = 0;

    for(int l = 1, r = 1;r <= n;r++) {
        pushQueue(sl, sr, s1, s2, a[r]);
        while(l <= r && getQueue(sl, sr, s1, s2) == k) {
            popQueue(sl, sr, s1, s2);
            l++;
        }
        res += l - 1;
    }

    cout << res << "\n";

    return 0;
}