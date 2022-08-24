#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

vector<pair<int, int> > s44;
vector<pair<int, int> > s45;
vector<pair<int, int> > vv;
map<vector<int>, vector<pair<int, int> > > mm;
vector<int> gg;

void init2(int a, int b) {
    vv.clear();
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            vv.push_back(make_pair(i, j));
    sort(vv.begin(), vv.end());
    gg.resize(a + b);
    do {
        random_shuffle(vv.begin(), vv.end());
        int n = a + b;
        for (int i = 0; i < n; ++i)
            gg[i] = i;
        for (int i = 0; i < vv.size(); ++i) {
            int x = vv[i].first;
            int y = vv[i].second + a;
            swap(gg[x], gg[y]);
        }
        int fl = 0;
        for (int i = 0; i < a; ++i)
            if (gg[i] >= a)
                fl = 1;
        for (int i = a; i < a + b; ++i)
            if (gg[i] < a)
                fl = 1;
        if (fl)
            continue;
        int x = 0;
        for (int i = 0; i < a; ++i)
            for (int j = i + 1; j < a; ++j)
                if (gg[i] > gg[j])
                    x ^= 1;
        if (x)
            continue;
        if (b == 4)
            s44 = vv;
        else
            s45 = vv;
        break;
    } while (true);
}

void init3(int n) {
    vv.clear();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            vv.push_back(make_pair(i, j));
    sort(vv.begin(), vv.end());
    gg.resize(n);
    do {
        for (int i = 0; i < n; ++i)
            gg[i] = i;
        for (int i = 0; i < vv.size(); ++i) {
            int a = vv[i].first;
            int b = vv[i].second;
            swap(gg[a], gg[b]);
        }
        mm[gg] = vv;
    } while (next_permutation(vv.begin(), vv.end()));
}

void init() {
    init2(4, 4);
    init2(4, 5);
    init3(4);
    init3(5);
}

vector<pair<int, int> > ans;

vector<int> pr;

void magic(int x, int a, int y, int b) {
    if (a == 4 && b == 4) {
        for (int i = 0; i < s44.size(); ++i) {
            int l = s44[i].first + x;
            int r = s44[i].second + y;
            swap(pr[l], pr[r]);
            ans.push_back(make_pair(l, r));
        }
    }
    else {
        for (int i = 0; i < s45.size(); ++i) {
            int l = s45[i].first + x;
            int r = s45[i].second + y;
            swap(pr[l], pr[r]);
            ans.push_back(make_pair(l, r));
        }
    }
}

void srt(int x, int l) {
    vector<int> tmp;
    for (int i = x; i < x + l; ++i)
        tmp.push_back(pr[i] - x);
    vector<pair<int, int> > go = mm[tmp];
    reverse(go.begin(), go.end());
    for (int i = 0; i < go.size(); ++i) {
        int a = go[i].first + x;
        int b = go[i].second + x;
        swap(pr[a], pr[b]); 
        ans.push_back(make_pair(a, b));
    }
}

int main() {
    init();
    int n;
    cin >> n;
    if (n % 4 == 2 || n % 4 == 3) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    pr.resize(n);
    for (int i = 0; i < n; ++i)
        pr[i] = i;
    for (int i = 0; i + 1 < n; i += 4) {
        for (int j = i + 4; j + 1 < n; j += 4) {
            int l1 = 4;
            int l2 = 4;
            if (j + 5 == n)
                ++l2;
            magic(i, l1, j, l2);
        }
    }
    for (int i = 0; i + 1 < n; i += 4) {
        int l = 4;
        if (i + 5 == n)
            ++l;
        srt(i, l);
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
    pr.resize(n);
    for (int i = 0; i < n; ++i)
        pr[i] = i;
    for (int i = 0; i < ans.size(); ++i) {
        int a = ans[i].first;
        int b = ans[i].second;
        swap(pr[a], pr[b]);
    }
    for (int i = 0; i < n; ++i)
        assert(pr[i] == i);
    return 0;
}