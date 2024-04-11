#ifdef LEONID_PROGRAMMER_AKA_LEOPRO
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

namespace {
    using namespace std;
//#define int long long
    using ll = long long;

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct castle {
    int x1, y1, x2, y2;
    castle *next_x1 = nullptr, *next_y1 = nullptr, *prev_x1 = nullptr, *prev_y1 = nullptr;
    castle *prev_x2 = nullptr, *prev_y2 = nullptr, *next_x2 = nullptr, *next_y2 = nullptr;

    bool small_group = false;

    castle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

struct direction {
    int castle::* dir, castle::* opp;
    castle *castle::*next, *castle::*prev;
    function<bool(int, int)> farther;

    direction(int castle::* dir, int castle::* opp, castle *castle::*next, castle *castle::*prev, const function<bool(int, int)> &farther)
            : dir(dir), opp(opp), next(next), prev(prev), farther(farther) {}

    void relax_farthest(int &farthest, castle *c) const { if (farther(c->*opp, farthest)) farthest = c->*opp; }

    bool gap_after(castle *cur, int farthest) const {
        return cur->*next != nullptr && cur->*next->*dir == farthest || farther(cur->*next->*dir, farthest);
    }

    castle *get_next(castle *cur) const { return cur->*next; }

    void erase(castle *c) const {
        castle *cprev = c->*prev;
        castle *cnext = c->*next;
        if (cprev != nullptr) cprev->*next = cnext;
        if (cnext != nullptr) cnext->*prev = cprev;
    }

    castle *init(vector<castle *> &castles) const {
        sort(castles.rbegin(), castles.rend(), [this](castle *a, castle *b) { return farther(a->*dir, b->*dir); });
        for (int i = 1; i < castles.size(); ++i) {
            castles[i]->*prev = castles[i - 1];
            castles[i - 1]->*next = castles[i];
        }
        castles.front()->*prev = nullptr;
        castles.back()->*next = nullptr;
        return castles.front();
    }

    void handle_n(castle *start, const function<void(castle *)> &handle, int n) const {
        for (int i = 0; i < n; ++i) {
            handle(start);
            start = start->*next;
        }
    }


    castle *find_first(castle *c, const function<bool(castle *)> &ok) const {
        for (; !ok(c); c = c->*next);
        return c;
    }
};


bool cut(castle *starts[4], direction dir[4]) {
    castle *cur[4] = {starts[0], starts[1], starts[2], starts[3]};
    int minus_inf = -1e9, plus_inf = 1e9;
    int farthest[4] = {minus_inf, plus_inf, minus_inf, plus_inf};
    int steps = 0;
    while (true) {
        steps++;
        for (int i = 0; i < 4; ++i) {
            dir[i].relax_farthest(farthest[i], cur[i]);
            if (dir[i].get_next(cur[i]) == nullptr) {
                return steps == 1;
            }
            if (dir[i].gap_after(cur[i], farthest[i])) {
                vector<castle *> small_group;
                dir[i].handle_n(starts[i], [&](castle *c) {
                    c->small_group = true;
                    small_group.push_back(c);
                }, steps);
                castle *big_start[4];
                for (int d = 0; d < 4; ++d) big_start[d] = dir[d].find_first(starts[d], [](castle *c) { return !c->small_group; });
                for (int d = 0; d < 4; ++d) for (castle *c : small_group) dir[d].erase(c);
                castle *small_start[4];
                for (int d = 0; d < 4; ++d) small_start[d] = dir[d].init(small_group);
                for (castle *c : small_group) c->small_group = false;
                return cut(small_start, dir) && cut(big_start, dir);
            }
            cur[i] = dir[i].get_next(cur[i]);
        }
    }
}

void solve() {
    autoint n;
    vector<castle *> castles(n);
    for (int i = 0; i < n; ++i) {
        autoint x1, y1, x2, y2;
        castles[i] = new castle(x1, y1, x2, y2);
    }
    direction directions[4] = {
            direction(&castle::x1, &castle::x2, &castle::next_x1, &castle::prev_x1, [](int x1, int x2) { return x1 > x2; }),
            direction(&castle::x2, &castle::x1, &castle::next_x2, &castle::prev_x2, [](int x1, int x2) { return x1 < x2; }),
            direction(&castle::y1, &castle::y2, &castle::next_y1, &castle::prev_y1, [](int y1, int y2) { return y1 > y2; }),
            direction(&castle::y2, &castle::y1, &castle::next_y2, &castle::prev_y2, [](int y1, int y2) { return y1 < y2; })
    };

    castle *starts[4];
    for (int i = 0; i < 4; ++i) starts[i] = directions[i].init(castles);
    cout << (cut(starts, directions) ? "YES" : "NO") << '\n';
}