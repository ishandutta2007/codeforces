    #pragma optimize "-O3"
    #include <bits/stdc++.h>
    using namespace std;
    typedef long double ld;
    typedef long long ll;
    const int maxN = (int)1e5 + 100;
    ll c[maxN][5];
    int n;
    vector < int > pos[maxN];
    bool lucky[maxN];
    int a[maxN];
    map < int, int > mp;
    ll ans = 0;
    vector < int > all_lucky;
    bool already[maxN];
    void solve(int l, int r) {
        int ind = lower_bound(all_lucky.begin(), all_lucky.end(), r) - all_lucky.begin();
        ll cur_val = 0;
        set < pair < int, int > > s;
        // if l .. r - 1 > [a, b]
        ans += c[r - 1 + 2][4] - c[l - 1 + 2][4] - c[r - l][1] * c[l - 1 + 1][3];
        if (r == n + 1) return ;
        cur_val = 0;
        s.insert(make_pair(1, r - 1));
        cur_val += c[r - 1 + 1][2];;
    //    cout << cur_val << " ?? " << endl;
        for (int i = ind; i + 1 < all_lucky.size(); i++) {
            if (s.empty()) break;
            if (!already[a[all_lucky[i]]]) {
                already[a[all_lucky[i]]] = true;
                for (auto v : pos[a[all_lucky[i]]]) {
                    if (v >= r) break;
                    auto it = --(s.lower_bound(make_pair(v + 1, -1)));
                    int x = it -> first;
                    int y = it -> second;
                    assert(x <= v && v <= y);
                    s.erase(it);
                    cur_val -= c[y - x + 1 + 1][2];
                   // cout << cur_val << " " << x << " " << y << " up" << endl;
                    if (x != v) {
                        s.insert(make_pair(x, v - 1));
                   //     cout << x << " " << v - 1 << endl;
                        cur_val += c[v - 1 - x + 1 + 1][2];
                    }
                    if (y != v) {
                        s.insert(make_pair(v + 1, y));
                  //      cout << v + 1 << " " << y << endl;
                        cur_val += c[y - v - 1 + 1 + 1][2];
                    }
                }
            }
            if (s.empty()) continue;
            ll tot = cur_val;
         //   cout << "now " << cur_val << endl;
            int nxt = all_lucky[i + 1];
            int cur_len = nxt - all_lucky[i];
        //    cout << nxt << " " << cur_len << " ?? " << l << " " << r << endl;
          //  cout << cur_len << " ?? " << (r - l);
            if (l != r) {
                auto it = --s.lower_bound(make_pair(l + 1, -1));
                int x = it->first;
                int y = it->second;
                assert(y == r - 1 && x <= l);
                int len1 = y - l + 1;
                int len2 = (y - x + 1) - len1;
            //    cout << x << " " << y << " gg" << endl;
                ans -= c[y - x + 1 + 1][2] * cur_len * (r - l + 1);
                ll coef = (c[y - x + 1 + 1][3] - c[len2 + 1][3] + c[y - x + 1 + 1][2]);
                ans += coef * cur_len;
            }
            ans += cur_val * cur_len * (r - l + 1);
          //  cout << ans << endl;
        }
        for (int v : all_lucky) {
            already[a[v]] = false;
        }
        //cout << ans << endl;
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
        c[0][0] = 1;
        for (int i = 1; i < maxN; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, 4); j++) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]] = 1;
            int x = a[i];
            lucky[i] = true;
            while (x) {
                if (x % 10 != 4 && x % 10 != 7) {
                    lucky[i] = false;
                    break;
                }
                x /= 10;
            }
            if (lucky[i]) all_lucky.push_back(i);
        }
        int lll = 1;
        for (auto& it : mp) {
            it.second = lll;
            lll++;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = mp[a[i]];
            pos[a[i]].push_back(i);
        }
        int prv = 0;
        all_lucky.push_back(n + 1);
       // solve(5, 7);
       // return 0;
        for (int i = 1; i <= n; i++) {
            if (lucky[i]) {
                solve(prv + 1, i);
                prv = i;
            }
        }
        if (prv != n) {
            solve(prv + 1, n + 1);
        }
        cout << ans;
        return 0;
    }