/*
    author:  Maksim1744
    created: 07.06.2021 14:20:15
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

// O(n*log)
vector<int> build_suf_array(string s, bool add_dollar = true) {
    if (add_dollar)
        s += '$';
    int n = s.size();
    vector<pair<int, int>> cur(s.size());
    for (int i = 0; i < s.size(); ++i) {
        cur[i] = make_pair(i, 0);
    }
    sort(cur.begin(), cur.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
        return s[a.first] < s[b.first];
    });
    for (int i = 1; i < s.size(); ++i) {
        cur[i].second = cur[i - 1].second + (s[cur[i].first] != s[cur[i - 1].first]);
    }
    vector<int> ind(n);
    vector<int> count(n);
    vector<pair<int, int>> tmp(n);
    for (int k = 1; k <= n; k *= 2) {
        for (int i = 0; i < n; ++i) {
            ind[cur[i].first] = cur[i].second;
        }
        for (int i = 0; i < n; ++i) {
            cur[i].first = (cur[i].first - k + n) % n;
            cur[i].second = ind[cur[i].first];
        }
        count.assign(count.size(), 0);
        for (int i = 0; i < n; ++i) {
            count[cur[i].second]++;
        }
        for (int i = 1; i < n; ++i)
            count[i] += count[i - 1];
        for (int i = 0; i < n; ++i)
            --count[i];
        for (int i = n - 1; i >= 0; --i) {
            tmp[count[cur[i].second]--] = make_pair(cur[i].first, 0);
        }
        swap(cur, tmp);
        for (int i = 1; i < n; ++i) {
            cur[i].second = cur[i - 1].second;
            if (ind[cur[i].first] != ind[cur[i - 1].first] || ind[(cur[i].first + k) % n] != ind[(cur[i - 1].first + k) % n])
                ++cur[i].second;
        }
    }
    vector<int> res(n);
    for (int i = 0; i < cur.size(); ++i) {
        res[i] = cur[i].first;
    }

    if (add_dollar)
        res.erase(res.begin());

    return res;
}

vector<int> build_lcp(const string &s, const vector<int> &suf_array) {
    int n = s.size();
    vector<int> lcp(n - 1);
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
        ind[suf_array[i]] = i;
    }
    int last = 1;
    for (int i = 0; i < n; ++i) {
        last = max(last - 1, 0);
        int i_cur = i;
        if (ind[i_cur] != 0) {
            int i_prev = suf_array[ind[i_cur] - 1];
            while (i_cur + last < s.size() && i_prev + last < s.size() && s[i_cur + last] == s[i_prev + last])
                ++last;
            lcp[ind[i_cur] - 1] = last;
        }
    }
    return lcp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto res = build_suf_array(s, false);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[res[i]] = i;
    }
    for (int i = 1; i < n; ++i) {
        if (p[i] > p[0]) {
            s.resize(i);
            break;
        }
    }
    string t = s;
    while (s.size() < k)
        s += t;
    s.resize(k);
    cout << s << '\n';

    return 0;
}