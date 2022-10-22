#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;
int n, a[N], b[N], ord[N];
vector<int> pos[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].emplace_back(i);
    }
    int tot = 0;
    for(int i = 1; i <= n; i++) if(sz(pos[i]) > 0) ord[++tot] = i;
    sort(ord + 1, ord + tot + 1, [&](int x, int y) {return sz(pos[x]) > sz(pos[y]); });
    while(1) {
        if(tot == 0) break;
        for(int i = 1; i <= tot; i++) {
            int x = ord[i];
            int y = pos[x].back();
            pos[x].pop_back();
            b[y] = ord[i % tot + 1];
        }
        while(tot > 0 && sz(pos[ord[tot]]) == 0) tot--;
    }
    for(int i = 1; i <= n; i++) cout << b[i] <<" ";
    cout << endl;
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}