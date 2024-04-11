#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s[2];
ll a[2][2];
const int maxN = (int)1e5 + 10;
int all[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int ans = n + 1;
    int x = 1;
    int y = n;
    for (int i = 1; i <= n; i++) {
        int nx = i;
        int ny = (n + i - 1) / i;
        if (nx + ny <= ans) {
            ans = nx + ny;
            x = nx;
            y = ny;
        }
    }
    int sz = 1;
    int cur = n;
    for (int block = 1; ;block++) {
        for (int j = max(1, cur - x + 1); ;j++) {
            if (all[j] != 0) break;
            if (j > n) break;
            all[j] = sz;
            sz++;
        }
        cur -= x;
        if (sz > n) break;
    }
    for (int i = 1; i <= n; i++) cout << all[i] << " ";
}