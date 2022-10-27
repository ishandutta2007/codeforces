#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];
int c[nax];
int nq;

void solve() {
    cin >> n >> nq;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        b[a[i]] += 1;
    }
    int lst = 0;

    for (int i = 1 ; (i + 1 < nax) ; ++ i) {
        c[i] = b[i] % 2;
        b[i + 1] += b[i] / 2;
    }
    set <pair <int, int>> setik;
    for (int i = 1 ; i < nax ;) {
        int j = i;
        while (j < nax && c[j] == c[i]) j += 1;
        if (c[i] == 1) {
            setik.emplace(i, j - 1);
        }
        i = j;
    }

    auto insert_to_setik = [&](pair <int, int> bar) {
        if (bar.first > bar.second) return;
        setik.emplace(bar);
        auto where = setik.find(bar);
        if (where != setik.begin() && prev(where)->second + 1 == where->first) {
            auto save_bar = bar; auto save_pre_bar = *prev(where);
            bar = make_pair(prev(where)->first, where->second);
            setik.erase(save_bar);
            setik.erase(save_pre_bar);
            setik.insert(bar);
        }

        where = setik.find(bar);
        if (next(where) != setik.end() && next(where)->first == where->second + 1) {
            auto save_bar = bar; auto save_next = *next(where);
            bar = make_pair(where->first, next(where)->second);
            setik.erase(save_bar);
            setik.erase(save_next);
            setik.insert(bar);
        }
    };


    for (int i = 1 ; i <= nq ; ++ i) {
        int k; cin >> k;
        int pos = a[k];
        auto it = setik.lower_bound(make_pair(pos, -1));

        {
            if ((it != setik.begin() && prev(it)->second >= pos) || (it != setik.end() && it->first <= pos)) {
                auto pre_pair = (it != setik.begin() && prev(it)->second >= pos) ? prev(it) : it;
                /// between some segments
                auto r_pair = make_pair(pos + 1, pre_pair->second);
                auto l_pair = make_pair(pre_pair->first, pos - 1);
                setik.erase(*pre_pair);
                insert_to_setik(r_pair);
                insert_to_setik(l_pair);
            } else {
                /// now it should not between any segment
                if (setik.empty()) exit(0);
                if (it == setik.end()) it = prev(it);
                auto new_pair = make_pair(pos, it->first - 1);
                auto r_pair = make_pair(it->first + 1, it->second);
                setik.erase(*it);
                insert_to_setik(new_pair);
                insert_to_setik(r_pair);
            }
        }

        cin >> a[k];
        pos = a[k];


        {
            auto it = setik.lower_bound(make_pair(pos + 1, -1));
            if ((it != setik.begin() && prev(it)->second < pos) || (it == setik.begin()))  {
                insert_to_setik(make_pair(pos, pos));
            } else {
                auto this_pair = *prev(it);
                it = prev(it);
                auto l_pair = make_pair(it->first, pos - 1);
                auto r_pair = make_pair(it->second + 1, it->second + 1);
                setik.erase(this_pair);
                insert_to_setik(l_pair);
                insert_to_setik(r_pair);
            }
        }

        cout << prev(setik.end())->second << '\n';
    }


    /**
        it's like big number addition

        basically, we should keep track the position where
        1'b stand
            1       1       1       1       1
        1) added 1 to 0'b position would not change much
        2) subtract 1 from 1'b position is the same
        3) adding 1 to odd position would need to find
            -next 0, then fill all 1 until next zero as zeros
        4) subtract 1 from 0'b position would need to find next 1
            then fill all 0 till next 1 as 1

        5) the query is just last position of 1

        set seems to do the work, but how?
        it makes sense to keep number as interval in set and then make split
    */
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (T = 1 ; T -- ;) {
        solve();
    }

}