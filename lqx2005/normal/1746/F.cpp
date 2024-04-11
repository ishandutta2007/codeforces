#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 3e5 + 10, T = 32;
mt19937_64 gen(__builtin_ia32_rdtsc());
struct fwt {
    ull f[N];
    void add(int x, ull v) { 
        for(; x < N; x += x & (-x)) f[x] += v; 
    }
    ull qry(int x) {
        ull sum = 0;
        for(; x > 0; x -= x & (-x)) sum += f[x];
        return sum;
    }
}t[T];
ull rd[T][N * 2];
int n, q, tot, a[N];
map<int, int> id;
int gid(int x) {
    if(id.count(x)) return id[x];
    id[x] = ++tot;
    FOR(i, 0, T - 1) rd[i][tot] = gen() % 1000000000000ll;
    return tot;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i], a[i] = gid(a[i]);
        FOR(j, 0, T - 1) t[j].add(i, rd[j][a[i]]);
    }
    FOR(i, 1, q) {
        int opt;
        cin >> opt;
        if(opt == 1) {
            int x, v;
            cin >> x >> v;
            v = gid(v);
            FOR(j, 0, T - 1) t[j].add(x, rd[j][v] - rd[j][a[x]]);
            a[x] = v;
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            int yes = 1;
            FOR(j, 0, T - 1) {
                if((t[j].qry(r) - t[j].qry(l - 1)) % k != 0) {
                    yes = 0;
                }
            }
            if(yes) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}