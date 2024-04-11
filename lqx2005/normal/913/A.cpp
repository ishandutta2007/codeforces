#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int p2 = 1;
    for(int i = 1; i <= n; i++) {
        p2 <<= 1;
        if(p2 > m) break;
    }
    m %= p2;
    cout << m << endl;
    return;
}
int main() {
    int t;
    for(t = 1; t--; solve());
    return 0;
}