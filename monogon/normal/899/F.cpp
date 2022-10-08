
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// for each character, keep list of indices
// fenwick tree of original indices
// delete index => all original indices of suffix +1
// for each character keep set of indices where it occurs
// lower_bound and iterate, deleting them

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ord;

const int N = 2e5 + 5;
int n, m, l, r;
char c;
string s;
set<int> st[256];
ord I;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    rep(i, 0, n) {
        st[(int) s[i]].insert(i + 1);
        I.insert(i + 1);
    }
    rep(i, 0, m) {
        cin >> l >> r >> c;
        l = *I.find_by_order(l - 1);
        r = *I.find_by_order(r - 1);
        while(true) {
            auto it = st[(int) c].lower_bound(l);
            if(it == st[(int) c].end() || *it > r) break;
            I.erase(*it);
            st[(int) c].erase(it);
        }
    }
    for(int x : I) {
        cout << s[x - 1];
    }
    cout << '\n';
}