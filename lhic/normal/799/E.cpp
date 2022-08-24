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

const ll INF = 1e16;
set<pair<ll, int> > ss;
ll c[210000];
int fl[210000];
vector<pair<ll, int> > v1;
vector<pair<ll, int> > v2;
vector<pair<ll, int> > v3;
int n, m, k;
int a;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%lld", c + i), ss.insert(make_pair(c[i], i));
    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        fl[x] |= 1;
    }
    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        fl[x] |= 2;
    }
    for (int i = 0; i < n; ++i) {
        if (fl[i] == 1)
            v1.push_back(make_pair(c[i], i));
        if (fl[i] == 2)
            v2.push_back(make_pair(c[i], i));
        if (fl[i] == 3)
            v3.push_back(make_pair(c[i], i));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    if (v1.size() + v3.size() < k || v2.size() + v3.size() < k) {
        cout << -1 << "\n";
        return 0;
    }
    ll ans = INF;
    int cur = 0;
    ll sum = 0;
    v1.resize(min((int)v1.size(), k));
    v2.resize(min((int)v2.size(), k));
    v3.resize(min((int)v3.size(), k));
    for (int i = 0; i < v1.size(); ++i) {
        ++cur;
        ss.erase(v1[i]);
        sum += v1[i].first;
    }
    int now1 = v1.size();
    for (int i = 0; i < v2.size(); ++i) {
        ++cur;
        ss.erase(v2[i]);
        sum += v2[i].first;
    }
    int now2 = v2.size();
    if (now1 >= k && now2 >= k) {
        while (cur < m) {
            sum += ss.begin()->first;
            ss.erase(ss.begin());
            ++cur;
        }
        if (cur == m)
            ans = sum;
    }
    for (int i = 0; i < v3.size(); ++i) {
        if (ss.count(v3[i])) {
            ss.erase(v3[i]);
            sum += v3[i].first;
            ++cur;
        }
        while (now1 + i + 1 > k) {
            --now1;
            --cur;
            ss.insert(v1[now1]);
            sum -= v1[now1].first;
        }
        while (now2 + i + 1 > k) {
            --now2;
            --cur;
            ss.insert(v2[now2]);
            sum -= v2[now2].first;
        }
        if (now1 + i + 1 >= k && now2 + i + 1 >= k) {
            while (cur < m) {
                sum += ss.begin()->first;
                ss.erase(ss.begin());
                ++cur;
            }
            if (cur == m)
                ans = min(ans, sum);
        }
    }
    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    return 0;
}