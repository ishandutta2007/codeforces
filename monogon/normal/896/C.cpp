
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

const int M = 1e9 + 7;

ll modpow(ll a, ll b, int y) {
    a %= y;
    ll ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % y;
        a = (a * a) % y;
        b /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; ll seed, vmax;
    cin >> n >> m >> seed >> vmax;
    auto rnd = [&]() {
        ll ret = seed;
        seed = (seed * 7 + 13) % M;
        return ret;
    };
    vector<pair<ll, int>> ve;
    vector<pair<ll, int>> ve2;
    rep(i, 0, n) {
        ll a = (rnd() % vmax) + 1;
        ve.push_back({a, 1});
    }
    auto compress = [&]() {
        ve2.clear();
        for(auto &pa : ve) {
            if(!ve2.empty() && ve2.back().first == pa.first) {
                ve2[sz(ve2) - 1] = {pa.first, ve2.back().second + pa.second};
            }else {
                ve2.push_back(pa);
            }
        }
        ve.swap(ve2);
    };
    // auto print = [&]() {
    //     for(auto &pa : ve) {
    //         rep(i, 0, pa.second) {
    //             cout << pa.first << ' ';
    //         }
    //     }
    //     cout << '\n';
    // };
    while(m--) {
        // print();
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n);
        int r = (rnd() % n);
        if(l > r) swap(l, r);
        ll x, y;
        if(op == 3) x = rnd() % (r - l + 1);
        else x = (rnd() % vmax) + 1;
        if(op == 4) y = (rnd() % vmax) + 1;

        if(op == 1) {
            ve2.clear();
            int k = sz(ve);
            int i = 0;
            int sum = 0;
            while(i < k) {
                int pref = 0;
                int amt = min(l - sum, ve[i].second);
                if(amt > 0) {
                    ve2.push_back({ve[i].first, amt});
                    sum += amt;
                    pref += amt;
                }
                if(sum >= l && sum < r + 1) {
                    amt = min(r - sum + 1, ve[i].second - pref);
                    if(amt > 0) {
                        ve2.push_back({ve[i].first + x, amt});
                        sum += amt;
                        pref += amt;
                    }
                }
                amt = ve[i].second - pref;
                if(amt > 0) {
                    ve2.push_back({ve[i].first, amt});
                }
                i++;
            }
            ve.swap(ve2);
            compress();
        }else if(op == 2) {
            ve2.clear();
            int k = sz(ve);
            int i = 0;
            int sum = 0;
            while(i < k) {
                int pref = 0;
                int amt = min(l - sum, ve[i].second);
                if(amt > 0) {
                    ve2.push_back({ve[i].first, amt});
                    sum += amt;
                    pref += amt;
                }
                if(sum >= l && sum < r + 1) {
                    amt = min(r - sum + 1, ve[i].second - pref);
                    if(amt > 0) {
                        ve2.push_back({x, amt});
                        sum += amt;
                        pref += amt;
                    }
                }
                amt = ve[i].second - pref;
                if(amt > 0) {
                    ve2.push_back({ve[i].first, amt});
                }
                i++;
            }
            ve.swap(ve2);
            compress();
        }else if(op == 3 || op == 4) {
            ve2.clear();
            int k = sz(ve);
            int i = 0;
            int sum = 0;
            while(i < k && sum < r + 1) {
                int amt = min(l - sum, ve[i].second);
                int pref = 0;
                if(amt > 0) {
                    sum += amt;
                    pref = amt;
                }
                if(sum >= l) {
                    amt = min(r - sum + 1, ve[i].second - pref);
                    if(amt > 0) {
                        ve2.push_back({ve[i].first, amt});
                        sum += amt;
                    }
                }
                i++;
            }
            if(op == 3) {
                sort(all(ve2));
                int sum = 0;
                for(auto &pa : ve2) {
                    sum += pa.second;
                    if(sum > x) {
                        cout << pa.first << '\n';
                        break;
                    }
                }
            }else {
                ll ans = 0;
                for(auto &pa : ve2) {
                    ans = (ans + pa.second * modpow(pa.first, x, y)) % y;
                }
                cout << ans << '\n';
            }
        }
    }
}