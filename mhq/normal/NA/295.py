#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> s;
    int cntA = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') cntA++;
    }
    cout << min((int)s.size(), 2 * cntA - 1);
    return 0;
}