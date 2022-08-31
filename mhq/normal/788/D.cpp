#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
set < int > byX, byY;
vector < int > fx = {0, 1, 500};
vector < int > fy = {0, 1, 1488, 329};
int QUE = 0;
int ask(int x, int y) {
    QUE++;
    assert(QUE <= 300000);
    cout << 0 << " " << x << " " << y << endl;
    int resp;
#ifdef DEBUG
    int best = 3e8;
    for (int v : fx) best = min(best, abs(v - x));
    for (int v : fy) best = min(best, abs(v - y));
    resp = best;
#else
    cin >> resp;
#endif
    return resp;
}
const int BUBEN = 2;
const int INF = (int)3e8;
int expected(int x, int y) {
    int dist = INF;
    if (!byX.empty()) {
        auto it = byX.lower_bound(x);
        if (it != byX.end()) {
            dist = min(dist, abs(*it - x));
        }
        if (it != byX.begin()) {
            --it;
            dist = min(dist, abs(*it - x));
        }
    }
    if (!byY.empty()) {
        auto it = byY.lower_bound(y);
        if (it != byY.end()) {
            dist = min(dist, abs(*it - y));
        }
        if (it != byY.begin()) {
            --it;
            dist = min(dist, abs(*it - y));
        }
    }
    return dist;
}
const int val = 100000000;
mt19937 rnd(228);

int gen() {
    ll f = (rnd() | ((ll)rnd() << 30LL)) % (2 * val + 1);
    return (int)(f - val);
}

bool is_X(int x) {
    if (x < -val || x > val) return false;
    for (int i = 0; i < BUBEN; i++) {
        int y = gen();
        if (ask(x, y) != 0) return false;
    }
    return true;
}

bool is_Y(int y) {
    if (y < -val || y > val) return false;
    for (int i = 0; i < BUBEN; i++) {
        int x = gen();
        if (ask(x, y) != 0) return false;
    }
    return true;
}

vector < pair < int, int > > intersect(int a, int b, int l, int r) {
    vector < pair < int, int > > ans;
    if (a <= min(l - 1, b)) {
        ans.emplace_back(a, min(l - 1, b));
    }
    if (max(r + 1, a) <= b) {
        ans.emplace_back(max(r + 1, a), b);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    vector < pair < int, int > > allX, allY;
    allX.emplace_back(-val, val);
    allY.emplace_back(-val, val);
    while (!allX.empty() && !allY.empty()) {
        auto t1 = allX.back();
        auto it = byX.lower_bound(t1.first);
        if (it != byX.end()) {
            int who = *it;
            if (who <= t1.second) {
                allX.pop_back();
                if (t1.first < who) allX.emplace_back(t1.first, who - 1);
                if (who < t1.second) allX.emplace_back(who + 1, t1.second);
                continue;
            }
        }
        auto t2 = allY.back();
        auto it2 = byY.lower_bound(t2.first);
        if (it2 != byY.end()) {
            int who = *it2;
            if (who <= t2.second) {
                allY.pop_back();
                if (t2.first < who) allY.emplace_back(t2.first, who - 1);
                if (who < t2.second) allY.emplace_back(who + 1, t2.second);
                continue;
            }
        }
        allX.pop_back();
        allY.pop_back();
        int midX = (t1.first + t1.second) / 2;
        int midY = (t2.first + t2.second) / 2;
        int d1 = ask(midX, midY);
        if (d1 < expected(midX, midY)) {
            for (int a : {-1, 1}) {
                if (is_X(midX + a * d1)) byX.insert(midX + a * d1);
            }
            for (int a : {-1, 1}) {
                if (is_Y(midY + a * d1)) byY.insert(midY + a * d1);
            }
            allX.emplace_back(t1);
            allY.emplace_back(t2);
            continue;
        }
        else {
            auto p1 = intersect(t1.first, t1.second, midX - d1 + 1, midX + d1 - 1);
            auto p2 = intersect(t2.first, t2.second, midY - d1 + 1, midY + d1 - 1);
            for (auto gg : p1) {
                allX.push_back(gg);
            }
            for (auto gg : p2) {
                allY.push_back(gg);
            }
        }
    }
//    cout << "HI " << endl;
//    for (int v : byX) cout << v << " ";
//    cout << endl;
//    for (int v : byY) cout << v << " ";
//    cout << endl;
//    for (auto it : allX) cout << it.first << " " << it.second << endl;
//    cout << "-----------" << endl;
//    for (auto it : allY) cout << it.first << " " << it.second << endl;
    if (!allX.empty()) {
        // vremenno
        byY.insert(-val - 1);
        byY.insert(val + 1);
        pair < int, int > best = {-2 * val, +2*val};
        int lst = -val - 1;
        for (auto it : byY) {
            if (it == -val - 1) continue;
            if (it - lst > best.first - best.second) {
                best.first = it;
                best.second = lst;
            }
            lst = it;
        }
        assert(best.first - best.second > 5000);
        byY.erase(-val - 1);
        byY.erase(val + 1);
        int y = (best.first + best.second) / 2;
        while (!allX.empty()) {
            auto t1 = allX.back();
            auto it = byX.lower_bound(t1.first);
            if (it != byX.end()) {
                int who = *it;
                if (who <= t1.second) {
                    allX.pop_back();
                    if (t1.first < who) allX.emplace_back(t1.first, who - 1);
                    if (who < t1.second) allX.emplace_back(who + 1, t1.second);
                    continue;
                }
            }
            int midX = (t1.first + t1.second) / 2;
            int d1 = ask(midX, y);
            allX.pop_back();
            if (d1 < expected(midX, y)) {
                for (int a : {-1, 1}) {
                    if (is_X(midX + a * d1)) byX.insert(midX + a * d1);
                }
                allX.emplace_back(t1);
                continue;
            }
            else {
                auto p1 = intersect(t1.first, t1.second, midX - d1 + 1, midX + d1 - 1);
                for (auto gg : p1) {
                    allX.push_back(gg);
                }
            }
        }
    }
    else if (!allY.empty()) {
        byX.insert(-val - 1);
        byX.insert(val + 1);
        pair < int, int > best = {-2 * val, +2*val};
        int lst = -val - 1;
        for (auto it : byX) {
            if (it == -val - 1) continue;
            if (it - lst > best.first - best.second) {
                best.first = it;
                best.second = lst;
            }
            lst = it;
        }
        assert(best.first - best.second > 5000);
        byX.erase(-val - 1);
        byX.erase(val + 1);
        int x = (best.first + best.second) / 2;
        while (!allY.empty()) {
            auto t2 = allY.back();
            auto it2 = byY.lower_bound(t2.first);
            if (it2 != byY.end()) {
                int who = *it2;
                if (who <= t2.second) {
                    allY.pop_back();
                    if (t2.first < who) allY.emplace_back(t2.first, who - 1);
                    if (who < t2.second) allY.emplace_back(who + 1, t2.second);
                    continue;
                }
            }
            allY.pop_back();
            int midY = (t2.first + t2.second) / 2;
            int d1 = ask(x, midY);
            if (d1 < expected(x, midY)) {
                for (int a : {-1, 1}) {
                    if (is_Y(midY + a * d1)) byY.insert(midY + a * d1);
                }
                allY.emplace_back(t2);
                continue;
            }
            else {
                auto p1 = intersect(t2.first, t2.second, midY - d1 + 1, midY + d1 - 1);
                for (auto gg : p1) {
                    allY.push_back(gg);
                }
            }
        }
    }
    cout << 1 << " " << byX.size() << " " << byY.size() << endl;
    for (int v : byX) cout << v << " ";
    cout << endl;
    for (int v : byY) cout << v << " ";
    cout << endl;
    return 0;
}