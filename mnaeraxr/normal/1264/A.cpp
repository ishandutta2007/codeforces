#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

void solve(){
    int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int last = a[n / 2];

    int g = 0;
    while (g < n && a[0] == a[g])
        ++g;

    int s = g + 1;
    while (s < n && s - g <= g)
        ++s;

    int last_s = a[s - 1];
    while (s < n && last_s == a[s])
        ++s;

    int b = s + 1;
    while (b < n && a[b] > last)
        ++b;

    if (b <= n / 2 && b - s > g) {
        cout << g << " " << s - g << " " << b - s << endl;
    } else {
        cout << "0 0 0" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t-->0){
        solve();
    }

    return 0;
}