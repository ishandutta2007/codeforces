#include <bits/stdc++.h>
using namespace std;
const int maxN = 5 * (int)1e5 + 10;
int n;
long long p[maxN];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    long long mx = 0;
    long long curans = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') curans += p[i];
    }
    mx = curans;
    long long cop = curans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') curans -= p[i];
        else curans += p[i];
        mx = max(mx, curans);
    }
    curans = cop;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'B') curans -= p[i];
        else curans += p[i];
        mx = max(mx, curans);
    }
    cout << mx;
    return 0;
}