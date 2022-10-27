#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
/// damn you codeblock, probably quit using soon


int main () {
    cin.tie(0)->sync_with_stdio(false);
    int q;

    cin >> q;

    int db = 0, a = 0;
    using ll = long long;

    ll sum_fire = 0, sum_light = 0;

    #define set multiset
    set <int> setik1, setik2;

    ll sum1 = 0, sum2 = 0;

    auto add = [&](int v) {
        if (!setik1.empty() && v > *setik1.begin()) {
            setik1.insert(v);
            sum1 += v;
        } else {
            setik2.insert(v);
            sum2 += v;
        }
    };

    auto del = [&] (int v) {
        if (setik1.count(v)) {
            sum1 -= v;
            setik1.erase(setik1.find(v));
        } else if (setik2.count(v)) {
            setik2.erase(setik2.find(v));
            sum2 -= v;
        } else abort();
    };

    auto my_resize = [&] (int sz) {
        while (setik1.size() > sz) {
            int w = *setik1.begin();
            assert(setik1.count(w));
            setik1.erase(setik1.begin());
            setik2.insert(w);
            sum1 -= w;
            sum2 += w;
        }

        while (setik1.size() < sz) {
            int w = *setik2.rbegin();
            sum2 -= w;
            sum1 += w;
            assert(setik2.count(w));
            setik1.insert(w);
            setik2.erase(setik2.find(w));
        }
    };

    set <int> light;
    int ct_fire = 0;

    while (q -- ) {
        int type, d;
        cin >> type >> d;

        if (type == 0) {
            sum_fire += d;
            if (d > 0) {
                ++ ct_fire;
                add(d);
            } else {
                -- ct_fire;
                del(-d);
            }
        } else if (type == 1) {
            sum_light += d;
            if (d > 0) ++ db, add(d), light.insert(d);
            else -- db, del(-d), light.erase(light.find(-d));

        } else assert(false);

        if (db == 0) {
            cout << sum_light + sum_fire << '\n';
        } else {
            int x = *light.begin();
            del(x);
            if (ct_fire > 0) {
                my_resize(db);
            } else my_resize(db - 1);
            cout << sum1 + sum_light + sum_fire << '\n';
            add(x);
        }

    }
}