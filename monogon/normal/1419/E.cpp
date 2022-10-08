
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        ll n;
        cin >> n;
        ll x = n;
        vector<pair<int, ll>> div;
        for(ll i = 2; i * i <= x; i++) {
            if(x % i == 0) {
                int cnt = 0;
                while(x % i == 0) {
                    cnt++;
                    x /= i;
                }
                div.emplace_back(cnt, i);
            }
        }
        if(x > 1) {
            div.emplace_back(1, x);
        }
        sort(div.rbegin(), div.rend());
        assert(!div.empty());
        if(sz(div) == 1) {
            ll p = 1;
            rep(i, 0, div[0].first) {
                p *= div[0].second;
                cout << p << ' ';
            }
            cout << '\n' << 0 << '\n';
        }else if(sz(div) == 2) {
            if(div[0].first == 1) {
                ll p = div[0].second, q = div[1].second;
                cout << p << ' ' << p * q << ' ' << q << '\n' << 1 << '\n';
            }else {
                ll p = div[0].second, q = div[1].second;
                int m = div[0].first, l = div[1].first;
                ll pp = 1;
                vector<ll> v1, v2;
                rep(i, 0, m + 1) {
                    ll qq = 1;
                    rep(j, 0, l + 1) {
                        if(j != 1 || (i != 1 && i != 2)) {
                            if(i > 0) {
                                v1.push_back(pp * qq);
                            }else if(j > 0) {
                                v2.push_back(pp * qq);
                            }
                        }
                        qq *= q;
                    }
                    pp *= p;
                }
                cout << p * q << ' ';
                for(ll x : v1) cout << x << ' ';
                cout << p * p * q << ' ';
                for(ll x : v2) cout << x << ' ';
                cout << '\n' << 0 << '\n';
            }
        }else {
            int k = sz(div);
            vector<vector<ll>> ve(k);
            vi cnt(k, 0);
            ll num = 1;
            vector<ll> prods(k, 1);
            set<ll> se;
            se.insert(1);
            rep(i, 0, k) {
                int j = (i + 1) % k;
                se.insert(div[i].second * div[j].second);
            }
            while(true) {
                int i = 0;
                while(i < k && cnt[i] == div[i].first) {
                    num /= prods[i];
                    prods[i] = 1;
                    cnt[i] = 0;
                    i++;
                }
                if(i == k) break;
                cnt[i]++;
                prods[i] *= div[i].second;
                num *= div[i].second;
                if(se.count(num) == 0) {
                    ve[i].push_back(num);
                }
            }
            rep(i, 0, k) {
                int j = (i + 1) % k;
                for(ll x : ve[i]) cout << x << ' ';
                cout << div[i].second * div[j].second << ' ';
            }
            cout << '\n' << 0 << '\n';
        }
    }
}