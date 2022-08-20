/*
    author:  Maksim1744
    created: 25.08.2020 18:10:23
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

struct Node {
    map<char, Node*> to;
    bool end = false;
    int ind;
};

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // vector<ll> cnt = {1, 0};
    vector<vector<string>> pos;
    pos.pb(vector<string>{""});
    pos.pb(vector<string>{});
    for (int n = 2; n <= 20; ++n) {
        ll ans = 0;
        vector<string> cur;
        for (int k = 2; k <= min(n, 9); ++k) {
            for (auto s : pos[n - k]) {
                s.pb('0' + k);
                cur.pb(s);
            }
            // ans += cnt[n - k];
        }
        // cnt.pb(ans);
        pos.pb(cur);
    }

    for (int n = 2; n <= 20; ++n) {
        vector<string> next;
        for (auto s : pos[n]) {
            bool good = false;
            for (int i = 0; i < s.size(); ++i) {
                int cur_sum = 0;
                for (int j = i; j < s.size(); ++j) {
                    cur_sum += s[j] - '0';
                    if (n % cur_sum == 0 && j - i + 1 != s.size()) {
                        good = true;
                        break;
                    }
                }
                if (good) break;
            }
            if (!good) next.pb(s);
        }
        swap(pos[n], next);
    }
    // for (int n = 0; n <= 20; ++n) {
    //     show(n, pos[n].size());
    // }

    string s;
    cin >> s;
    int x;
    cin >> x;
    if (x == 1) {
        cout << count(s.begin(), s.end(), '1') << '\n';
        return 0;
    }

    Node *root = new Node();
    vector<Node*> nodes = {root};
    root->ind = 0;
    for (auto t : pos[x]) {
        auto node = root;
        for (auto c : t) {
            if (!node->to.count(c)) {
                node->to[c] = new Node();
                nodes.pb(node->to[c]);
                nodes.back()->ind = nodes.size() - 1;
            }
            node = node->to[c];
        }
        node->end = true;
    }
    vector<string> corr(nodes.size());

    function<void(Node*, string)> connect = [&](Node *node, string s) {
        corr[node->ind] = s;
        for (char c = '1'; c <= '9'; ++c) {
            if (node->to.count(c)) {
                connect(node->to[c], s + c);
            } else {
                s.pb(c);
                for (int i = 0; i <= s.size(); ++i) {
                    bool has = true;
                    Node *cur = root;
                    for (int j = i; j < s.size(); ++j) {
                        if (!cur->to.count(s[j])) {
                            has = false;
                            break;
                        }
                        cur = cur->to[s[j]];
                    }
                    if (has) {
                        node->to[c] = cur;
                        break;
                    }
                }
                s.pop_back();
            }
        }
    };
    connect(root, "");

    // for (auto node : nodes) {
    //     cout << node->ind << ": ";
    //     for (char c = '1'; c <= '9'; ++c) {
    //         cout << c << "->" << node->to[c]->ind << ' ';
    //     }
    //     cout << endl;
    // }

    show(pos[x]);

    vector<vector<int>> dp(s.size() + 1, vector<int>(nodes.size(), inf));
    vector<vector<int>> p(s.size() + 1, vector<int>(nodes.size(), -1));
    dp[0][0] = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < nodes.size(); ++j) {
            if (nodes[j]->end) continue;
            if (dp[i][j] == inf) continue;
            if (dp[i + 1][j] > dp[i][j] + 1) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                p[i + 1][j] = j;
            }
            int j1 = nodes[j]->to[s[i]]->ind;
            // if (j == 0)
            //     show(i, j, s[i], j1);
            if (!nodes[j1]->end && dp[i + 1][j1] > dp[i][j]) {
                dp[i + 1][j1] = min(dp[i + 1][j1], dp[i][j]);
                p[i + 1][j1] = j;
            }
        }
    }
    // show(dp[2][0]);

    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i]->end)
            dp.back()[i] = inf;
    }

    // vector<int> path;
    // int u = mini(dp.back());
    // while (u != -1) {
    //     path.pb(u);
    //     u = p[(int)s.size() - path.size() + 1][u];
    // }
    // reverse(path.begin(), path.end());
    // show(path);
    // vector<string> spath;
    // for (auto u : path) {
    //     spath.pb(corr[u]);
    // }
    // show(spath);

    cout << mine(dp.back()) << '\n';

    // vector<string> al;
    // int c = 0;
    // map<string, int> num;
    // for (auto u : pos) {
    //     // c += u.size();
    //     for (auto i : u) {
    //         num[i] = al.size();
    //         al.pb(i);
    //     }
    // }
    // show(c);
    // string s;
    // cin >> s;
    // int ans = 0;
    // int x;
    // cin >> x;
    // if (x == 1) {
    //     cout << count(s.begin(), s.end(), '1') << '\n';
    //     return 0;
    // }
    // if (x < 10) {
    //     string t;
    //     for (auto c : s) {
    //         if (c == '0' + x) {
    //             ++ans;
    //         } else {
    //             t.pb(c);
    //         }
    //     }
    //     s = t;
    // }

    // vector<string> dif;
    // vector<int> pos1;
    // pos1.pb(0);
    // for (int i = 0; i < s.size(); ++i) {
    //     if (s[i] == '1') {
    //         pos1.pb(i);
    //     }
    // }
    // pos1.pb(s.size());

    // for (int i = 0; i + 1 < pos1.size(); ++i) {
    //     if (pos1[i] + 1 < pos1[i + 1]) {
    //         dif.pb(s.substr(pos1[i] + 1, pos1[i + 1] - pos1[i] - 1));
    //     }
    // }

    // for (auto s : dif) {
    //     vector<vector<int>> dp(s.size() + 1, vector<int>(al.size(), 1e9));
    //     dp[0][num[""]] = 0;
    //     for (int i = 1; i <= s.size(); ++i) {
    //         char c = s[i - 1];
    //         int k = c - '0';
    //         assert(k >= 2);
    //     }
    // }

    return 0;
}