/*
    25.03.2019 14:55:00
*/

#include <bits/stdc++.h>

using namespace std;

// #ifdef HOME
// #define TAG_LENGTH 45
// #define LR_LEFT left
// #define LR_RIGHT right
// #define LR_VALUE value
// #define LR_SECOND_VALUE mn
// #include "C:/C++ libs/print.cpp"
// #define showl cout << endl;
// #define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
// #else
// #define show(...) 42;
// #define showt(...) 42;
// #define showl 42;
// #define shows 42;
// #define print(...) 42;
// #define printTree(...) 42;
// #define printLRTree(...) 42;
// #define printMatrix(...) 42;
// #endif

int main() {
    auto start_time = clock();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int k;
        string s, a, b;
        cin >> k >> s >> a >> b;
        string p(k, '_');
        for (int i = 0; i < k; ++i) {
            p[i] = 'a' + i;
        }
        // show(a.substr(0,10));
        // show(b.substr(0,10));
        // show(s.substr(0,10));
        bool ok = true;
        int ind = 0;
        string to(k, '_');
        int n = s.length();
        // show(n);
        vector<bool> can(k, true);
        // vector<int> prev(k);
        // vector<int> bext(k);
        // for (int i = 0; i < k; ++i) {
        //     prev[i] = i - 1;
        //     bext[i] = i + 1;
        // }
        while (ind < n && a[ind] == b[ind]) {
            if (to[s[ind] - 'a'] == '_') {
                if (!can[a[ind] - 'a']) {
                    ok = false;
                    break;
                }
                to[s[ind] - 'a'] = a[ind];
                can[a[ind] - 'a'] = false;
            } else if (to[s[ind] - 'a'] != a[ind]) {
                ok = false;
                break;
            }
            ++ind;
        }
        if (!ok) {
            cout << "NO\n";
        } else if (ind == n) {
            cout << "YES\n";
            vector<char> can_left;
            for (int i = 0; i < k; ++i) {
                if (can[i])
                    can_left.push_back('a' + i);
            }
            for (int i = 0; i < k; ++i) {
                if (to[i] == '_') {
                    to[i] = can_left.back();
                    can_left.pop_back();
                }
            }
            cout << to << '\n';
        } else {
            while (ind < n) {
                if ((long double)(clock() - start_time) > 4.9 * CLOCKS_PER_SEC) {
                    // cout << ind << ' ' << n << '\n';
                    break;
                }
                // showt(ind, to, can);
                if (to[s[ind] - 'a'] != '_') {
                    if (to[s[ind] - 'a'] < a[ind] || to[s[ind] - 'a'] > b[ind]) {
                        ok = false;
                        break;
                    } else {
                        if (to[s[ind] - 'a'] > a[ind]) {
                            a = string(n, 'a');
                        }
                        if (to[s[ind] - 'a'] < b[ind]) {
                            b = string(n, 'a' + k - 1);
                        }
                    }
                } else {
                    if (a[ind] == b[ind]) {
                        if (!can[a[ind] - 'a']) {
                            ok = false;
                            break;
                        } else {
                            can[a[ind] - 'a'] = false;
                            // int i0 = a[ind] - 'a';
                            // while (i0 >= 0 && !can[i0])
                            //     --i0;
                            // next[i0] = next[a[ind] - 'a'];
                            to[s[ind] - 'a'] = a[ind];
                            ++ind;
                            continue;
                        }
                    }
                    bool middle = false;
                    for (int i = a[ind] + 1; i < b[ind]; ++i) {
                        if (can[i - 'a']) {
                            middle = true;
                            to[s[ind] - 'a'] = i;
                            can[i - 'a'] = false;
                            break;
                        }
                    }
                    if (middle) {
                        break;
                    }
                    if (!can[a[ind] - 'a'] && !can[b[ind] - 'a']) {
                        ok = false;
                        break;
                    } else if (!can[a[ind] - 'a']) {
                        can[b[ind] - 'a'] = false;
                        to[s[ind] - 'a'] = b[ind];
                        a = string(n, 'a');
                    } else if (!can[b[ind] - 'a']) {
                        can[a[ind] - 'a'] = false;
                        to[s[ind] - 'a'] = a[ind];
                        b = string(n, 'a' + k - 1);
                    } else {
                        bool oka = true;
                        auto to_ = to;
                        auto can_ = can;
                        auto ind_ = ind;
                        can[a[ind] - 'a'] = false;
                        to[s[ind] - 'a'] = a[ind];
                        ++ind;
                        while (ind < n) {
                            // showt(ind, to, can);
                            if (to[s[ind] - 'a'] != '_'){
                                if (to[s[ind] - 'a'] < a[ind]) {
                                    // show("here");
                                    oka = false;
                                    break;
                                } else if (to[s[ind] - 'a'] > a[ind]) {
                                    break;
                                }
                            } else {
                                bool found = false;
                                for (int i = k - 1; i >= a[ind] -'a'; --i) {
                                    if (can[i]) {
                                        to[s[ind] - 'a'] = 'a' + i;
                                        can[i] = false;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    // show("here2");
                                    oka = false;
                                    break;
                                }
                                if (to[s[ind] - 'a'] > a[ind]) {
                                    break;
                                }
                            }
                            ++ind;
                        }
                        if (oka)
                            break;
                        to = to_;
                        can = can_;
                        ind = ind_;
                        can[b[ind] - 'a'] = false;
                        to[s[ind] - 'a'] = b[ind];
                        ++ind;
                        while (ind < n) {
                            // showt(ind, to, can);
                            if (to[s[ind] - 'a'] != '_'){
                                if (to[s[ind] - 'a'] > b[ind]) {
                                    ok = false;
                                    break;
                                } else if (to[s[ind] - 'a'] < b[ind]) {
                                    break;
                                }
                            } else {
                                bool found = false;
                                for (int i = 0; i <= b[ind] -'a'; ++i) {
                                    if (can[i]) {
                                        to[s[ind] - 'a'] = 'a' + i;
                                        can[i] = false;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    ok = false;
                                    break;
                                }
                                if (to[s[ind] - 'a'] < b[ind]) {
                                    break;
                                }
                            }
                            ++ind;
                        }
                        break;
                    }
                }
                ++ind;
            }
            // if (tests == 1) {
            //     cout << "NO\n";
            //     continue;
            // }
            if (ok) {
                cout << "YES\n";
                vector<char> can_left;
                for (int i = 0; i < k; ++i) {
                    if (can[i])
                        can_left.push_back('a' + i);
                }
                for (int i = 0; i < k; ++i) {
                    if (to[i] == '_') {
                        to[i] = can_left.back();
                        can_left.pop_back();
                    }
                }
                cout << to << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}