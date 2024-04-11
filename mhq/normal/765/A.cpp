#include <bits/stdc++.h>
using namespace std;
int n;
int cnt1, cnt2;
string home;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> home;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        if (x[x.size() - 3] == home[0] && x[x.size() - 2] == home[1] && x[x.size() - 1] == home[2]) cnt1++;
        if (x[0] == home[0] && x[1] == home[1] && x[2] == home[2]) cnt2++;
    }
    if (cnt1 == cnt2) {
        cout << "home";
    }
    else cout << "contest";
    return 0;
}