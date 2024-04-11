#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, sn;
int a[nax];
int lst[nax];
int fst[nax];
int b[nax];
bool mark[nax];

void go(int x) {

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (!fst[a[i]]) fst[a[i]] = i;
        lst[a[i]] = i;
    }

    int cnt = 0;
    int cur = 1, to = lst[a[1]];
    mark[1] = true;
    while (true) {
        if (cur > n) break;
        int new_to = 0;
        for (int j = cur ; j < to ; ++ j) {
            new_to = max(new_to, lst[a[j]]);
        }
        mark[to] = true;
        if (new_to <= to) {
            cur = to + 1;
            mark[cur] = 1;
            to = lst[a[cur]];
        } else {
            cur = to + 1;
            to = new_to;
        }

    }
//    for (int i = 1 ; i <= n ; ++ i) {
//        cout << int(mark[i]) << ' ';
//    }
//    cout << '\n';
    cout << n - count(mark + 1, mark + 1 + n, true) << '\n';
}