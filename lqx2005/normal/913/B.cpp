#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e3 + 10;
int n, deg[N], fa[N], cnt[N];
void solve() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        cin >> fa[i];
        deg[fa[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            cnt[fa[i]]++;
        }
    }
    int flag = 1;
    for(int i = 1; i <= n; i++) if(deg[i] > 0 && cnt[i] < 3) flag = 0;
    puts(flag ? "Yes" : "No");
    return;
}
int main() {
    int t;
    for(t = 1; t--; solve());
    return 0;
}