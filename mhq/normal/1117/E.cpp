#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string t;
const int maxN = 35;
int val[maxN][maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> t;
    n = t.size();
    string p1 = t, p2 = t, p3 = t;
    for (int i = 0; i < n; i++) {
        p1[i] = (i % 26) + 'a';
        p2[i] = ((i / 26) % 26) + 'a';
        p3[i] = (((i / 26) / 26) % 26) + 'a';
        val[p1[i] - 'a'][p2[i] - 'a'][p3[i] - 'a'] = i;
    }
    string t1, t2, t3;
    cout << "? " << p1 << endl;
    cin >> t1;
    cout << "? " << p2 << endl;
    cin >> t2;
    cout << "? " << p3 << endl;
    cin >> t3;
    string ans = t;
    for (int i = 0; i < n; i++) {
        int pos = val[t1[i] - 'a'][t2[i] - 'a'][t3[i] - 'a'];
        ans[pos] = t[i];
    }
    cout << "! " << ans << endl;
}