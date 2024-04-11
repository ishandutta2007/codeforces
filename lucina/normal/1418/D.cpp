#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, q;
int p[nax];

set <int> setik;
map <int, int> ct;
multiset <int> setik2;

int get_ans() {
    if (setik.empty()) return 0;
    //assert(!setik.empty());
    int far = *setik.rbegin() - *setik.begin();
    return setik2.empty() ? far : far - *setik2.rbegin();
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;


    for (int i = 1 ; i <= n ; ++ i) {
        cin >> p[i];
        ct[p[i]] += 1;
    }

    for (auto &it : ct) {
        setik.insert(it.first);
    }

    for (auto it = setik.begin(); it != setik.end() ; ++ it) {
        if (next(it) != setik.end()) {
            setik2.insert(*next(it) - *it);
        }
    }

    cout << get_ans() << '\n';

    for (; q -- ;) {
        int type, pos;
        cin >> type >> pos;

        if (type == 1) {
            if (!ct.count(pos)) {
                setik.insert(pos);
                auto it = setik.find(pos);
                if (it != setik.begin()) {
                    setik2.insert(pos - *prev(it));
                }
                if (next(it) != setik.end()) {
                    setik2.insert(*next(it) - pos);
                }
                if (it != setik.begin() && next(it) != setik.end()) {
                    setik2.erase(setik2.find(*next(it) - *prev(it)));
                }
            }
            ct[pos] += 1;
        } else {
            ct[pos] -= 1;
            if (ct[pos] == 0) {
                auto it = setik.find(pos);
                if (it != setik.begin()) {
                    setik2.erase(setik2.find(pos - *prev(it)));
                }
                if (next(it) != setik.end()) {
                    setik2.erase(setik2.find(*next(it) - pos));
                }
                if (it != setik.begin() && next(it) != setik.end()) {
                    setik2.insert(*next(it) - *prev(it));
                }
                ct.erase(pos);
                setik.erase(it);
            }
        }
        cout << get_ans() << '\n';
    }




}
/*
    ZZZZZZZ
*/