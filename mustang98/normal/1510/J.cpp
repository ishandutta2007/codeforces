/**
 *  created: 12/04/2021, 12:02:34
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> check(int n, const vector<pair<int, int>> &blocks, int C) {
    //cout << C << endl;
    const int S = 1 + n - C;
    int first = 0, cur_sum = 0;
    vector<pair<int, pair<int, int>>> add;
    for (auto p : blocks) {
        int L = p.first - C;
        if (L < 0) {
            return {};
        }
        int sum = L - cur_sum;
        if (sum < 0 || sum == 1) {
            return {};
        }
        if (sum) {
            if (C == 0) {
                return {};
            }
            if (C == 1 && sum % 2) {
                return {};
            }
            int cnt = (sum + C) / (C + 1);
            if (first + sum - cnt > L) {
                return {};
            }
            add.push_back({first, {sum, cnt}});
        }
        add.push_back({L, {C + p.second, -1}});
        cur_sum += sum;
        cur_sum += add.back().second.first + 1;
        first = add.back().first + add.back().second.first + 1;
    }
    //cout << "#" << C << endl;
    int need = S - cur_sum;
    vector<int> after;
    if (need) {
        if (C == 0 || need == 1) {
            return {};
        }
        if (C == 1 && need % 2) {
            return {};
        }
        while (need) {
            if (need >= C + 1) {
                after.push_back(C);
                need -= C + 1;
            } else {
                if (need == 1) {
                    assert(after.size());
                    after.back() -= 1;
                    after.push_back(1);
                    need -= 1;
                } else {
                    after.push_back(need - 1);
                    need = 0;
                }
            }
            cur_sum += after.back() + 1;
        }
    }
    //cout << "#" << C << endl;
    vector<int> res;
    for (auto p : add) {
        if (p.second.second == -1) {
            res.push_back(p.second.first);
        } else {
            int sum = p.second.first;
            bool added = 0;
            while (sum) {
                if (sum >= C + 1) {
                    res.push_back(C);
                    sum -= C + 1;
                    added = 1;
                } else {
                    if (sum >= 2) {
                        res.push_back(sum - 1);
                        break;
                    } else {
                        assert(added);
                        --res.back();
                        res.push_back(1);
                        break;
                    }
                }
            }
        }
    }
    for (int x : after) {
        res.push_back(x);
    }
    return res;
}

pair<vector<int>, bool> solve(const string &s) {
    int n = s.size();
    vector<pair<int, int>> blocks;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            int start = i;
            while (i < n && s[i] == '#') {
                ++i;
            }
            blocks.push_back({start, i - start});
            --i;
        }
    }
    if (blocks.empty()) {
        return {{}, true};
    }
    for (int C = 0; C <= n + 1 && C * blocks.size() <= n + 1; ++C) {
        auto res = check(n, blocks, C);
        if (!res.empty()) {
            return {res, true};
        }
    }
    return {{}, false};
}

string get_string(int n, vector<int> v) {
    int S = 0;
    for (int x : v) {
        S += x + 1;
    }
    if (!(0 <= S && S <= n + 1)) {
        return "$";
    }
    const int C = 1 + n - S;
    int l = 0;
    string ans(n, '_');
    for (int x : v) {
        if (l + C <= l + x - 1) {
            fill(ans.begin() + l + C, ans.begin() + l + x, '#');
        }
        l += x + 1;
    }
    return ans;
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(1);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cout << get_string(3, {1, 1}) << endl;
    //return 0;
    if (0) {
        while (true) {
            int n = rnd(1, 50);
            n = 100000;
            vector<int> v;
            int sum = 0;
            while (sum + 2 <= n + 1) {
                if (rnd(2)) {
                    break;
                }
                int x = rnd(1, n - sum);
                sum += x + 1;
                v.push_back(x);
            }
            shuffle(v.begin(), v.end(), generator);
            string s = get_string(n, v);
            assert(s != "$");
            //cout << s << endl;
            auto ans = solve(s);
            if (!ans.second || get_string(s.size(), ans.first) != s) {
                cout << endl << s << endl;
                for (int x : v) {
                    cout << x << " ";
                }
                exit(2);
            }
            cout << "+";
        }
    }
    string s;
    cin >> s;
    auto ans = solve(s);
    if (ans.second && s != get_string(s.size(), ans.first)) {
        ans.second = false;
    }
    if (ans.second) {
        printf("%d\n", ans.first.size());
        for (int x : ans.first) {
            printf("%d ", x);
        }
        puts("");
    } else {
        puts("-1");
    }
    return 0;
}