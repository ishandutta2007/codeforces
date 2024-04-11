/*
    author:  Maksim1744
    created: 28.10.2020 00:52:49
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    n *= 6;
    vector<int> a(n / 2);
    cin >> a;
    --a;
    string s(n, '0');
    for (auto k : a) {
        s[k] = '1';
    }
    show(s);

    vector<vector<int>> ans;
    vector<vector<int>> inds(n / 3);

    char cur = '1';

    // bool good = true;
    string t = s;
    // char cur = '1' - n / 3 % 2;
    vector<vector<int>> from(n / 3);
    vector<char> who(n / 3);
    int ind = 0;
    map<int, vector<int>> need;
    vector<int> st;
    for (int i = 0; i < t.size(); ++i) {
        st.pb(i);
        while (st.size() >= 3 && t[st[st.size() - 1]] == t[st[st.size() - 2]] && t[st[st.size() - 2]] == t[st[st.size() - 3]]) {
            for (auto u : need[st[st.size() - 2]]) {
                from[ind].pb(u);
            }
            for (auto u : need[st[st.size() - 3]]) {
                from[ind].pb(u);
            }
            who[ind] = t[st.back()];
            inds[ind] = {st[st.size() - 3], st[st.size() - 2], st[st.size() - 1]};
            st.pop_back();
            st.pop_back();
            st.pop_back();
            if (!st.empty()) {
                need[st.back()].pb(ind);
            }
            ++ind;
        }
    }
    show(inds);
    // if (t == "") {
    //     show(t);
    //     show(from);
    //     show(who);
    // }
    vector<int> to(from.size(), -1);
    for (int i = 0; i < from.size(); ++i) {
        for (auto j : from[i]) {
            to[j] = i;
        }
    }
    // if (t == "") {
    //     show(to);
    // }
    map<char, vector<int>> ends;
    for (int i = 0; i < to.size(); ++i) {
        if (from[i].empty() && to[i] == -1)
            ends[who[i]].pb(i);
    }
    // if (t == "") {
    //     show(ends);
    //     show(cur);
    // }
    bool good = true;
    for (int i = 0; i < n / 3; ++i) {
        int ind = -1;
        for (int j = 0; j < from.size(); ++j) {
            bool ok = true;
            for (auto k : from[j]) {
                if (!from[k].empty()) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            if (from[j].empty()) continue;
            if (who[j] == cur) continue;
            if (ind == -1 || from[ind].size() > from[j].size()) ind = j;
        }
        if (ind == -1) {
            for (int j = 0; j < from.size(); ++j) {
                bool ok = false;
                for (auto &k : from[j]) {
                    if (from[k].empty()) {
                        ok = true;
                        swap(k, from[j].back());
                    }
                }
                if (!ok) continue;
                if (from[j].empty()) continue;
                if (who[j] == cur) continue;
                if (ind == -1 || from[ind].size() > from[j].size()) ind = j;
            }
        }
        // if (t == "") {
        //     show(ind, ends, cur);
        // }
        if (ind != -1) {
            if (cur == '1' || true) ans.pb(inds[from[ind].back()]);
            from[ind].pop_back();
            if (from[ind].empty() && to[ind] == -1)
                ends[who[ind]].pb(ind);
        } else if (!ends[cur].empty()) {
            if (cur == '1' || true) ans.pb(inds[ends[cur].back()]);
            ends[cur].pop_back();
        } else {
            good = false;
            break;
        }
        cur = '0' + '1' - cur;
    }
    assert(good);

    for (auto v : ans) {
        ++v;
        cout << v << '\n';
    }

    return 0;
}