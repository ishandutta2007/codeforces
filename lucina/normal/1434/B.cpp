#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int f[nax];
int g[nax];

void no() {
    cout << "NO";
    exit(0);
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    stack <int> bar;

    cin >> n;


    for (int i = 1 ;i  <= 2 * n ; ++ i) {
        char s;
        cin >> s;
        if (s == '-') {
            int val;
            cin >> val;
            g[i] = val;
            if (bar.empty()) no();
            int when = bar.top();
            bar.pop();
            f[when] = val;
        } else {
            bar.push(i);
        }
    }

    if (!bar.empty()) no();
    set <int> foo;

    for (int i = 1 ; i <= 2 * n ; ++ i) {
        if (f[i] > 0) {
            foo.insert(f[i]);
        } else {
            if (g[i] != *foo.begin()) no();
            foo.erase(foo.begin());
        }
    }
    cout << "YES\n";

    for (int i = 1 ; i <= 2 * n ; ++ i)
        if (f[i] > 0) cout << f[i] << ' ';
    cout << '\n';

}
/*
    Good Luck
        -Lucina
*/