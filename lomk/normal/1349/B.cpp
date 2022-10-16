/*input
1
5 3
1 1 3 1 3
5 3
5 5 1 1 3
5 3
1 5 2 6 1
1 6
6
3 2
1 2 3
4 3
3 1 2 3
10 3
1 2 3 4 5 6 7 8 9 10
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

int n, m;
vector<int> a;

vector<int> pos;
bool check() {
    if (n == 1) {
        return (a[0] == m);
    }
    bool ok = false;
    loop(i, 0, n - 1) {
        if (a[i] == m) {
            ok = true;
            break;
        }
    }
    if (!ok) return false;
    loop(i, 0, n - 1) {
        if (a[i] < m) continue;
        pos.push_back(i);
    }
    loop(i, 1, pos.size() - 1) {
        if (pos[i] - pos[i - 1] <= 2) return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        a.clear(); pos.clear();
        cin >> n >> m;
        loop(i, 1, n) {
            int t; cin >> t;
            a.push_back(t);
        }
        if (check()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}