/*input
6
1 2
1 3
1 4
2 5
2 6

5
1 2
1 3
1 4
2 5

3
1 2
2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define int long long
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
const int N = 1e5 + 5;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}

vector<int> a[N];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    loop(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    loop(i, 1, n) {
        if (a[i].size() == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}