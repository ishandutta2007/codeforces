#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
const int N = 1e5 + 10, V = 88;
int ask(vi a) {
    cout << "? ";
    cout << sz(a) << " ";
    for(auto x : a) cout << x <<" ";
    cout << endl;
    string res;
    cin >> res;
    return res == "YES";
}
int guess(int x) {
    cout << "! " << x << endl;
    string res;
    cin >> res;
    return res == ":)";
}
int chkmin(int &x, int y) {
    if(x > y) return x = y, 1;
    return 0;
}
int dpr[V][N], dpc[V][N];
void solve(vi o, vi t) {
    if(sz(o) + sz(t) <= 2) {
        vi id = o;
        id.insert(id.end(), t.begin(), t.end());
        for(auto u : id) {
            if(guess(u)) return;
        }
        assert(0);
    }
    vi lo(o.begin(), o.begin() + sz(o) / 2), ro(o.begin() + sz(o) / 2, o.end());
    vi lt(t.begin(), t.begin() + sz(t) / 2), rt(t.begin() + sz(t) / 2, t.end());
    if(sz(lo) < sz(ro) && sz(lt) <= sz(rt)) {
        lt.emplace_back(rt.back());
        rt.pop_back();
    }
    vi q = lo;
    q.insert(q.end(), lt.begin(), lt.end());
    if(ask(q)) {
        swap(lo, ro), swap(lt, rt);
    }
    vi no = lt;
    vi nt = ro;
    nt.insert(nt.end(), rt.begin(), rt.end());
    solve(no, nt);
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> id(n);
    FOR(i, 0, n - 1) id[i] = i + 1;
    solve({}, id);
    return 0;
}