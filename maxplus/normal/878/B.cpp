#include <bits/stdc++.h>


using namespace std;

using pint = pair<int, int>;

map<int, pint> m, mm, mmm;
map<int, int> cnt;
int n, k, r, t;

int pop(int c) {
    if (--cnt[c] == 0)
        cnt.erase(c);
    return cnt.size();
}

void intrasquash(map<int, pint> &m) {
    m.begin()->second.second = 1;
    for (auto it = next(m.begin()); it != m.end(); )
        if (it->second.first == prev(it)->second.first)
            if ((it->second.second = prev(it)->second.second + 1) == k)
                for (int i = (advance(it, -k + 1), 0); i < k; ++i)
                    pop(it->second.first),
                    it = m.erase(it);
            else
                ++it;
        else
            it++->second.second = 1;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k >> r;
    for (int i = 0; i < n; ++i)
        cin >> t, m[i] = {t, 1}, ++cnt[t];
    intrasquash(m);
    mm = m;
    int eb = 0, ee = 0;
    while (cnt.size() > 1 && mm.begin()->second.first == mm.rbegin()->second.first) {
        int am = mm.rbegin()->second.second, ams = 0, t = mm.begin()->second.first;
        auto it = mm.begin();
        while (it->second.first == t)
            ++it, ++ams;
        if (am + ams < k)
            break;
        ee += am;
        eb += k - am;
        for (int i = 0; i < am; ++i)
            pop(t),
            mm.erase(prev(mm.end()));
        for (int i = 0; i < k - am; ++i)
            pop(t),
            it = mm.erase(prev(it));
    }
    if (cnt.size() == 1) {
        mmm = m;
        for (int i = 0; i < ee; ++i)
            mmm.erase(prev(mmm.end()));
        map<int, pint> mmm2;
        for (auto it = next(m.begin(), eb); it != m.end(); ++it)
            mmm2[it->first + k + n] = it->second;
        intrasquash(mmm);
        intrasquash(mmm2);
        int mid = (r - 2ll) * cnt.begin()->second % k;
        while (mmm.size() && mmm.rbegin()->second.first == cnt.begin()->first)
            ++mid, mmm.erase(prev(mmm.end()));
        while (mmm2.size() && mmm2.begin()->second.first == cnt.begin()->first)
            ++mid, mmm2.erase(mmm2.begin());
        if (mid %= k)
            cout << mmm.size() + mmm2.size() + mid;
        else {
            for (auto el: mmm2)
                mmm.insert(el);
            if (mmm.size())
                intrasquash(mmm);
            cout << mmm.size();
        }
    }
    else
        cout << m.size() + mm.size() * (r - 1ll);
    return 0;
}