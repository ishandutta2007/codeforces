#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
bool is_clear = true;
int qqqq = 0;
void cl() {
    if (is_clear) return;
    cout << "R" << endl;
    is_clear = true;
}
bool inQ(int x) {
    qqqq++;
    assert(qqqq <= (3 * n * n / (2 * k)));
    is_clear = false;
    cout << "? " << x << endl;
    char resp;
    cin >> resp;
    return (resp == 'Y');
}
pair < vector < int >, vector < int > > get_unique(vector < int >& a, vector < int >& b) {
    if (a.empty()) return {{}, b};
    if (b.empty()) return {a, {}};
    assert(a.size() <= k && b.size() <= k);
    cl();
    int to_add = 2 * k + 1 - a.size() - b.size();
    vector < bool > okA(a.size(), true);
    for (int i = 0; i < a.size(); i++) {
        inQ(a[i]);
    }
    vector < bool > okB(b.size(), true);
    for (int i = 0; i < b.size(); i++) {
        if (inQ(b[i])) okB[i] = false;
    }
    for (int j = 0; j < to_add; j++) inQ(a.back());
    for (int i = 0; i + 1 < a.size(); i++) {
        if (inQ(a[i])) okA[i] = false;
    }
    vector < int > a1, b1 = {};

    for (int i = 0; i < a.size(); i++) {
        if (okA[i]) a1.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        if (okB[i]) {
            b1.push_back(b[i]);
        }
    }
    return {a1, b1};
}
vector < int > solve(int l, int r) {
    if (r - l + 1 == k) {
        vector < int > good;
        cl();
        for (int i = l; i <= r; i++) {
            if (!inQ(i)) good.push_back(i);
        }
        return good;
    }
    int mid = (l + r) / 2;
    auto a = solve(l, mid);
    auto b = solve(mid + 1, r);
    vector < vector < int > > allA, allB;
    map < int, int > sz;
    allA.resize((a.size() + k - 1) / k);
    allB.resize((b.size() + k - 1) / k);
    for (int i = 0; i * k < a.size(); i++) {
        int from = i * k;
        int to = min((int)a.size() - 1, from + k - 1);
        vector < int > hs_now;
        for (int j = from; j <= to; j++) hs_now.push_back(a[j]);
        allA.push_back(hs_now);
    }
    for (int i = 0; i * k < b.size(); i++) {
        int from = i * k;
        int to = min((int)b.size() - 1, from + k - 1);
        vector < int > hs_now;
        for (int j = from; j <= to; j++) hs_now.push_back(b[j]);
        allB.push_back(hs_now);
    }

    for (int i = 0; i < allA.size(); i++) {
        for (int j = 0; j < allB.size(); j++) {
            auto res = get_unique(allA[i], allB[j]);
            allA[i] = res.first;
            allB[j] = res.second;
        }
    }
    vector < int > fin;
    for (auto& it : allA) {
        for (int v : it) fin.push_back(v);
    }

    for (auto& it : allB) {
        for (int v : it) fin.push_back(v);
    }
    return fin;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //n = 1024;
    //k = 16;
    cin >> n >> k;
    int gg = solve(1, n).size();
    cout << "! " << gg << endl;
    return 0;
}