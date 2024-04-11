/*
    author:  Maksim1744
    created: 04.04.2021 22:24:42
*/

#include "bits/stdc++.h"

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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

struct Node {
    string s;
    vector<Node*> ch;
};

bool islet(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

Node *parse(string s) {
    {
        int b = 0;
        vector<string> ss;
        int last = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++b;
            } else if (s[i] == ')') {
                --b;
            } else if (s[i] == '|' && b == 0) {
                ss.pb(s.substr(last, i - last));
                last = i + 1;
            }
        }
        ss.pb(s.substr(last, s.size()));
        if (ss.size() != 1) {
            Node *n = new Node();
            n->s = "|";
            for (auto t : ss)
                n->ch.pb(parse(t));
            return n;
        }
    }
    Node *n = new Node();
    n->s = '-';
    int ind = 0;
    // show(s);
    while (ind < s.size()) {
        Node *cur;
        if (s[ind] == '(') {
            int b = 1;
            int r = ind + 1;
            while (b != 0) {
                if (s[r] == '(') ++b;
                else if (s[r] == ')') --b;
                ++r;
            }
            cur = parse(s.substr(ind + 1, r - ind - 2));
            ind = r;
        } else {
            int r = ind;
            string t;
            while (r < s.size() && islet(s[r]))
                ++r;
            cur = new Node();
            cur->s = s.substr(ind, r - ind);
            ind = r;
            show(cur->s, ind, s);
            if (cur->s.size() >= 2 && ind < s.size() && (s[ind] == '?' || s[ind] == '*' || s[ind] == '+')) {
                cur->s.pop_back();
                n->ch.pb(cur);
                cur = new Node();
                cur->s.pb(s[ind - 1]);
            }
        }
        while (ind < s.size()) {
            if (s[ind] == '?' || s[ind] == '*' || s[ind] == '+') {
                Node *n2 = new Node();
                n2->s.pb(s[ind]);
                n2->ch.pb(cur);
                cur = n2;
            } else {
                break;
            }
            ++ind;
        }
        // show(cur->s, ind);
        n->ch.pb(cur);
    }
    while (n->ch.size() == 1 && n->s == "-")
        n = n->ch[0];
    return n;
}

void print(Node *n, int len = 0) {
    #ifndef HOME
    return;
    #endif
    cout << string(len, ' ') << n->s << endl;
    for (auto c : n->ch)
        print(c, len + 2);
}

pair<vector<string>, int> build(Node *n) {
    if (n->s == "|") {
        vector<pair<vector<string>, int>> ch;
        int w = 0;
        int h = 0;
        for (auto c : n->ch) {
            ch.pb(build(c));
            w = max(w, (int)ch.back().first[0].size());
            h += ch.back().first.size();
        }
        vector<string> res(h + (int)n->ch.size() - 1, string(w + 6, ' '));
        int curh = 0;
        int first = -1;
        int last = -1;
        for (int i = 0; i < ch.size(); ++i) {
            if (i >= 1) {
                ++curh;
            }
            if (i >= 1) {
                curh += ch[i - 1].first.size();
            }
            for (int j = 0; j < w + 6; ++j)
                res[curh + ch[i].second][j] = '-';
            res[curh + ch[i].second][0] = '+';
            res[curh + ch[i].second].back() = '+';
            res[curh + ch[i].second][w + 4] = '>';
            res[curh + ch[i].second][2] = '>';
            if (first == -1) first = curh + ch[i].second;
            last = curh + ch[i].second;
            for (int j = 0; j < ch[i].first.size(); ++j)
                for (int k = 0; k < ch[i].first[0].size(); ++k)
                    res[curh + j][k + 3] = ch[i].first[j][k];
        }
        for (int j = first; j <= last; ++j) {
            if (res[j][0] != '+') {
                res[j][0] = res[j].back() = '|';
            }
        }
        return {res, first};
    } else if (n->s == "-") {
        int minup = 0, mindown = 0;
        vector<pair<vector<string>, int>> ch;
        int w = 0;
        for (auto c : n->ch) {
            ch.pb(build(c));
            if (w != 0)
                w += 2;
            w += ch.back().first[0].size();
            minup = max(minup, ch.back().second);
            mindown = max(mindown, (int)ch.back().first.size() - ch.back().second - 1);
        }
        show(ch);
        show(w);
        vector<string> res(minup + mindown + 1, string(w, ' '));
        int pos = 0;
        for (int i = 0; i < ch.size(); ++i) {
            show(i, pos);

            for (int j = 0; j < ch[i].first.size(); ++j)
                for (int k = 0; k < ch[i].first[0].size(); ++k)
                    res[j + minup - ch[i].second][pos + k] = ch[i].first[j][k];

            if (i) {
                res[minup][pos - 2] = '-';
                res[minup][pos - 1] = '>';
            }
            pos += ch[i].first[0].size();
            pos += 2;
        }
        return {res, {minup}};
    } else if (n->s == "+") {
        assert(n->ch.size() == 1);
        auto [res, ind] = build(n->ch[0]);
        res.pb(string(res[0].size(), ' '));
        res.pb(string(res[0].size(), '-'));
        for (int i = 0; i < res.size(); ++i) {
            res[i].insert(res[i].begin(), ' ');
            res[i].insert(res[i].begin(), ' ');
            res[i].insert(res[i].begin(), ' ');
            res[i].pb(' ');
            res[i].pb(' ');
            res[i].pb(' ');
        }
        for (int i = ind; i < res.size(); ++i) {
            res[i][0] = '|';
            res[i].back() = '|';
        }
        res[ind][0] = res[ind].back() = res.back()[0] = res.back().back() = '+';
        res[ind][1] = res[ind][res[ind].size() - 3] = '-';
        res.back()[2] = res.back()[res[ind].size() - 3] = res.back()[res[ind].size() - 2] = '-';
        res.back()[1] = '<';
        res[ind][2] = '>';
        res[ind][res[ind].size() - 2] = '>';
        return {res, ind};
    } else if (n->s == "?") {
        assert(n->ch.size() == 1);
        auto [res, ind] = build(n->ch[0]);
        res.insert(res.begin(), string(res[0].size(), ' '));
        res.insert(res.begin(), string(res[0].size(), '-'));
        for (int i = 0; i < res.size(); ++i) {
            res[i].insert(res[i].begin(), ' ');
            res[i].insert(res[i].begin(), ' ');
            res[i].insert(res[i].begin(), ' ');
            res[i].pb(' ');
            res[i].pb(' ');
            res[i].pb(' ');
        }
        ind += 2;
        for (int i = 0; i < ind; ++i) {
            res[i][0] = '|';
            res[i].back() = '|';
        }
        res[ind][0] = res[ind].back() = res[0][0] = res[0].back() = '+';
        res[ind][1] = res[ind][res[ind].size() - 3] = '-';
        res[0][2] = res[0][res[ind].size() - 3] = res[0][res[ind].size() - 2] = '-';
        res[0][1] = '-';
        res[0][res[0].size() - 2] = '>';
        res[ind][2] = '>';
        res[ind][res[ind].size() - 2] = '>';
        res.insert(res.begin(), string(res[0].size(), ' '));
        return {res, 1};
    } else if (n->s == "*") {
        assert(n->ch.size() == 1);
        auto [res, ind] = build(n->ch[0]);
        res.insert(res.begin(), string(res[0].size(), ' '));
        res.insert(res.begin(), string(res[0].size(), '-'));
        for (int i = 0; i < res.size(); ++i) {
            res[i].insert(res[i].begin(), ' ');
            res[i].insert(res[i].begin(), ' ');
            res[i].insert(res[i].begin(), ' ');
            res[i].pb(' ');
            res[i].pb(' ');
            res[i].pb(' ');
        }
        ind += 2;
        for (int i = 0; i < res.size(); ++i) {
            res[i][0] = '|';
            res[i].back() = '|';
        }
        res[ind][0] = res[ind].back() = res[0][0] = res[0].back() = '+';
        res[ind][1] = res[ind][res[ind].size() - 3] = '-';
        res[0][2] = res[0][res[ind].size() - 3] = res[0][res[ind].size() - 2] = '-';
        res[0][1] = '-';
        res[0][res[0].size() - 2] = '>';
        res[ind][2] = '>';
        res[ind][res[ind].size() - 2] = '>';
        res.pb(res[1]);
        res.pb(res[0]);
        res.back()[1] = '<';
        res.back()[res.back().size() - 2] = '-';
        res.insert(res.begin(), string(res[0].size(), ' '));
        return {res, 1};
    } else {
        string s = n->s;
        vector<string> res(3, string(s.size() + 4, ' '));
        for (int i = 0; i < res[0].size(); ++i) {
            res[0][i] = '-';
            res[2][i] = '-';
        }
        res[0][0] = res[1][0] = res[2][0] = '+';
        res[0].back() = res[1].back() = res[2].back() = '+';
        for (int j = 0; j < s.size(); ++j)
            res[1][j + 2] = s[j];
        return {res, 1};
    }
    return {{}, 0};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    auto root = parse(s);
    print(root);
    auto [ans, ind] = build(root);
    for (int i = 0; i < ans.size(); ++i) {
        ans[i].insert(ans[i].begin(), ' ');
        ans[i].insert(ans[i].begin(), ' ');
        ans[i].insert(ans[i].begin(), ' ');
        ans[i].pb(' ');
        ans[i].pb(' ');
        ans[i].pb(' ');
    }
    ans[ind][0] = 'S';
    ans[ind][1] = '-';
    ans[ind][2] = '>';
    ans[ind][ans[ind].size() - 1] = 'F';
    ans[ind][ans[ind].size() - 2] = '>';
    ans[ind][ans[ind].size() - 3] = '-';
    cout << ans.size() << ' ' << ans[0].size() << '\n';
    for (string s : ans)
        cout << s << '\n';
    cerr << "done" << endl;

    return 0;
}