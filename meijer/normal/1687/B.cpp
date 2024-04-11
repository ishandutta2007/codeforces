#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int n, m;
string s;
int a[N], sa[N];

int query() {
    cout << "? " << s << endl;
    int res;
    cin >> res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    s.assign(m,'0');
    for (int i=0; i<m; i++) {
        fill(all(s), '0');
        s[i] = '1';
        a[i] = query();
    }

    iota(sa,sa+m,0);
    sort(sa,sa+m,[](int i, int j) {
        return a[i] > a[j];
    });
    
    fill(all(s), '1');
    int total = query();
    for (int i=0; i<m-1; i++) {
        int j = sa[i];
        s[j] = '0';
        int expected = total - a[j];
        int res = query();
        if (res == expected) {
            s[j] = '1';
        } else {
            s[j] = '0';
            total = res;
        }
    }
    cout << "! " << total << endl;
}