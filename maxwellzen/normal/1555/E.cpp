#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

const ll identity = 0;
const ll SZ = 1e6+10;
ll sum[4*SZ], lazy[4*SZ];
void init() { for (int i = 0; i < 4*SZ; i++) sum[i]=lazy[i]=identity; }
ll combine(ll A, ll B) { return min(A, B); }
ll combineUpd(ll A, ll B) { return A+B; }
void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = identity;
}
void pull(int index) { sum[index] = combine(sum[2*index], sum[2*index+1]); }
ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return 1;
    if (lo <= L && R <= hi) return sum[index];
    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}
void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }
    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

int n, m, l, r, w;
vector<array<int, 3>> segs;

bool path() {
    return query(1, m-1) != 0;
}

void add(int l, int r) {
    update(l+1, r, 1);
}

void sub(int l, int r) {
    update(l+1, r, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    F0R(i, n) {
        cin >> l >> r >> w;
        segs.pb({w, l-1, r-1});
    }
    sort(all(segs));
    l=0, r=0;
    int ans = 1e9;
    while (l<n) {
        while (r<n && !path()) {
            add(segs[r][1], segs[r][2]);
            r++;
        }
        if (!path()) break;
        while (l<n && path()) {
            sub(segs[l][1], segs[l][2]);
            if (!path()) {
                add(segs[l][1], segs[l][2]);
                break;
            }
            l++;
        }
        // cout << segs[l][0] << ' ' << segs[r-1][0] << endl;
        ans = min(ans, segs[r-1][0]-segs[l][0]);
        sub(segs[l][1], segs[l][2]);
        l++;
    }
    cout << ans << '\n';
}