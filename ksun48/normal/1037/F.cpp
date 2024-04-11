#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;

LL get(LL lnum, LL rnum, LL k){
    k--;
    LL ans = 0;
    LL v = rnum / k;
    rnum -= k * v;
    ans += lnum * v;
    ans %= MOD;
    v = lnum / k;
    lnum -= k * v;
    ans += rnum * v;
    ans %= MOD;
    ans += max(0LL, lnum + rnum - k - 1LL);
    if(lnum > 0 && rnum > 0) ans++;
    return ans % MOD;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<pair<LL,LL> > f;
    for(int i = 0; i < n; i++){
        f.push_back({a[i], i});
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    set<int> r;
    r.insert(-1);
    r.insert(n);
    LL ans = 0;
    for(auto x : f){
        int idx = x.second;
        LL val = x.first;
        r.insert(idx);
        int lnum = idx - *prev(r.find(idx));
        int rnum = *next(r.find(idx)) - idx;
        LL g = get(lnum, rnum, k) - 1;
        ans += (g * val) % MOD;
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    ans %= MOD;
    cout << ans << '\n';
}