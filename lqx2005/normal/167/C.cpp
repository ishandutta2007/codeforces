#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
map<pair<ll, ll>, int> SG;
int calc(ll x, ll y) {
    if(x < y) swap(x, y);
    if(y == 0) return 0;
    if(SG.count(make_pair(x, y))) return SG[make_pair(x, y)];
    auto &res = SG[make_pair(x, y)];
    res = 0;
    if(!calc(x % y, y)) return res = 1;
    ll z = x / y;
    if(y % 2 == 1) return res = (z + 1) % 2;
    if(z % (y + 1) == 0) return res = 1;
    return res = (z % (y + 1) + 1) % 2;
}
mt19937_64 rnd(__builtin_ia32_rdtsc());
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(; t--; ) {
        ll a, b;
        cin >> a >> b;
        int res = calc(a, b);
        if(res) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}