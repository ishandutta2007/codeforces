#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <set>
# include <algorithm>

using namespace std;

using pii = pair<int, int>;
#define INF         1011111111
//*************************************************************************************
template<class T>
int sign(T x) {
    return x > 0 ? 1 : x < 0 ? -1 : 0;
}
const int N = 1000008;

int arr[N];
long long a[N];

int ans = 1;
set<pii> s;
multiset<int> lens;
set<pii>::iterator insert(int l, int r) {
    lens.insert(r - l);
    return s.insert({l, r}).first;
}
void erase(int l, int r) {
    lens.erase(lens.find(r - l));
    s.erase({l, r});
}
template<class T>
void erase(T p) {
    int l = p->first;
    int r = p->second;
    lens.erase(lens.find(r - l));
    s.erase(p);
}
int sig(int pos) {
    return sign(a[pos]);
}
void resolve(set<pii>::iterator it, bool resPrev, bool resNext) {
    if (resPrev && it != s.begin()) {
        auto prev = std::prev(it);
        int lit = it->first;
        int rit = it->second;
        int lprev = prev->first;
        int rprev = prev->second;
        if (sig(rprev) && sig(lit) && sig(rprev) >= sig(lit)) {
            erase(lit, rit);
            erase(lprev, rprev);
            it = insert(lprev, rit);
        }
    }
    if (resNext) {
        auto next = std::next(it);
        if (next != s.end()) {
            auto prev = it;
            it = next;
            int lit = it->first;
            int rit = it->second;
            int lprev = prev->first;
            int rprev = prev->second;
            if (sig(rprev) && sig(lit) && sig(rprev) >= sig(lit)) {
                erase(lit, rit);
                erase(lprev, rprev);
                insert(lprev, rit);
            }
        }
    }
}
void upd(int pos, int val) {
    int prevSign = sign(a[pos]);
    a[pos] += val;
    int newSign = sign(a[pos]);
    if (newSign == prevSign) return;
    auto it = s.upper_bound({pos, INF});
    --it;
    int l = it->first;
    int r = it->second;
    erase(it);
    bool connectLeft = (pos == l) || (sig(pos - 1) >= newSign && newSign != 0 && sig(pos - 1) != 0);
    bool connectRight = (pos == r) || (sig(pos + 1) <= newSign && newSign != 0 && sig(pos + 1) != 0);
    if (connectLeft && connectRight) {
        it = insert(l, r);
        resolve(it, 1, 1);
    } else if (connectLeft) {
        it = insert(l, pos);
        resolve(it, 1, 0);
        insert(pos + 1, r);
    } else if (connectRight) {
        it = insert(pos, r);
        resolve(it, 0, 1);
        insert(l, pos - 1);
    } else {
        insert(l, pos - 1);
        insert(pos, pos);
        insert(pos + 1, r);
    }
}
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    --n;
    s.insert({0, 0});
    s.insert({n + 1, n + 1});
    for (int i = 0; i < n; ++i) {
        a[i + 1] = arr[i + 1] - arr[i];
    }
    int l = 1;
    for (int i = 2; i <= n + 1; ++i) {
        if (a[i] == 0 || a[i - 1] == 0 || sign(a[i]) > sign(a[i - 1])) {
            insert(l, i - 1);
            l = i;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if (!n) {
            puts("1");
            continue;
        }
        if (l > 1) {
            upd(l - 1, x);
        }
        if (r <= n) {
            upd(r, -x);
        }
        printf("%d\n", *lens.rbegin() + 2);
    }
    
    return 0;
}