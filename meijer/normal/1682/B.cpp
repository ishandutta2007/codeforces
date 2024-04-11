#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int p[N], sp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        for (int i=0; i<n; i++)
            cin >> p[i];
        for (int i=0; i<n; i++)
            sp[i] = p[i];
        sort(sp,sp+n);
        vector<int> dif;
        for (int i=0; i<n; i++) {
            if (p[i] != sp[i]) {
                dif.push_back(p[i]);
            }
        }
        int ans = (1<<20) - 1;
        for (int x : dif) ans &= x;
        cout << ans << endl;
    }
}