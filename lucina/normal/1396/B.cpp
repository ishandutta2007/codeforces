#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];

bool solve() {
    cin >> n;
    multiset <int, greater<int>> setik;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        setik.insert(a[i]);
    }

    bool turn = true;

    int lst_choose = -1;

    while (!setik.empty()) {
        int v = *setik.begin();
        int new_lst_choose = v - 1;
        setik.erase(setik.begin());
        if (lst_choose > 0) setik.insert(lst_choose);
        lst_choose = new_lst_choose;
        turn ^= 1;
    }
    return turn ^ 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "T" : "HL") << '\n';
    }
}
/*
    Long time no CF round...
*/