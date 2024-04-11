#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define sz(a) int((a).size())
#define ll long long
#define db double
#define vi vector<int>
using namespace std;
const int N = 2e5 + 10;
int n, fa[N];
string str;
vector<int> id[N];
int gf(int x) {return fa[x] == x ? x : fa[x] = gf(fa[x]); }
int me(int x, int y) {
    x = gf(x), y = gf(y);
    if(x == y) return 0;
    return fa[x] = y, 1;
}
void solve() {
    cin >> n;
    n *= 2;
    FOR(i, 0, n) fa[i] = i, id[i].clear();
    cin >> str;
    int top = 0;
    FOR(i, 0, n - 1) {
        id[top].emplace_back(i);
        if(str[i] == '(') {
            top++;
        } else {
            id[top].clear();
            top--;
            while(sz(id[top]) > 1) {
                int x = id[top].back();
                id[top].pop_back();
                int y = id[top].back();
                me(x, i);
            }
            me(id[top].back(), i);
        }
    }
    int cnt = 0;
    FOR(i, 0, n - 1) if(gf(i) == i) cnt++;
    cout << cnt << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
}