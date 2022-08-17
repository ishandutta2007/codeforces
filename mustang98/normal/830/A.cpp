#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>
#include <unistd.h>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 3000, inf = 1000111222;

int pn, kn;
ll op;
vector<ll> ppl, keys;
vector<pair<ll, ll> > segm;

bool check(ll tm) {
    segm.clear();
    for (int i = 0; i < ppl.size(); ++i) {
        if (abs(op - ppl[i]) > tm) return false;
        ll ost = (tm - abs(op - ppl[i])) / 2;
        ll l = op, r = ppl[i];
        if (l > r) swap(l, r);
        l -= ost;
        r += ost;
        segm.PB(MP(l, r));
    }
    sort(segm.begin(), segm.end());
    int curk = 0;
    for (int i = 0; i < segm.size(); ++i) {
        while (curk < keys.size() && keys[curk] < segm[i].F) curk++;
        if (curk == keys.size() || keys[curk] > segm[i].S) return false;
        curk++;
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> pn >> kn >> op;
    ll a;
    for (int i = 0; i < pn; ++i) {
        cin >> a;
        ppl.PB(a);
    }
    for (int i = 0; i < kn; ++i) {
        cin >> a;
        keys.PB(a);
    }
    sort(ppl.begin(), ppl.end());
    sort(keys.begin(), keys.end());
    ll l = 0, r = 6LL * inf;
    if (check(0)) {
        cout << 0;
        return 0;
    }
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
    return 0;
}