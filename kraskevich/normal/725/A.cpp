#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> was(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '>')
            break;
        was[i] = true;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '<')
            break;
        was[i] = true;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        if (was[i])
            res++;
    cout << res << endl;
    return 0;
}