#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
string s;
int mt[nax];

int parse(int l, int r) {
    if (l > r) return 0;
    int res = 0;
    while (l < r) {
        int nxt = mt[l];
        res += parse(l + 1, nxt - 1);
        l = nxt + 1;
    }
    res += 1;
    return res;
}

void solve() {
    cin >> n >> s;
    vector <int> stk;
    n *= 2;
    for (int i = 0 ; i < n ; ++ i) {
        if (s[i] == '(') {
            stk.push_back(i);
            continue;
        }
        mt[stk.back()] = i;
        stk.pop_back();
    }
    cout << parse(0, n - 1) << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    combined round~
    which faces?
    :D ? :E ? :O ? X<
*/