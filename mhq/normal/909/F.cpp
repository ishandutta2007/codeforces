#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = (int)1e5 + 10;
int ans1[maxN];
int ans2[maxN];
vector < int > pws;
void solve1(int n) {
    if (n == 0) return ;
    if (n % 2 == 1) {
        return ;
    }
    int pw = 1;
    while (2 * pw <= n) {
        pw = pw * 2;
    }
    //cout << pw;
    for (int i = 0; i <= n - pw; i++) {
        ans1[pw + i] = pw - i - 1;
        ans1[pw - i - 1] = pw + i;
    }
    solve1(2 * pw - n - 2);
}
void solve2(int n) {
    if (n == 7) {
        ans2[1] = 3;
        ans2[2] = 6;
        ans2[3] = 5;
        ans2[4] = 7;
        ans2[5] = 1;
        ans2[6] = 2;
        ans2[7] = 4;
        return ;
    }
    if (n == 6) {
        ans2[1] = 3;
        ans2[2] = 6;
        ans2[3] = 2;
        ans2[4] = 5;
        ans2[5] = 1;
        ans2[6] = 4;
        return ;
    }
    if (n <= 5) return ;
    int pw = 1;
    while (2 * pw <= n) {
        pw = pw * 2;
        pws.push_back(pw);
    }
    if (n == pw) return ;
    for (int i = n; i >= pws[pws.size() - 1] + 1; i--) {
        ans2[i] = i  - 1;
    }
    ans2[pws[pws.size() - 1]] = n;
    solve2(pws[pws.size() - 1] - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    solve1(n);
    if (ans1[1] != 0) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << ans1[i] << " ";
        }
        cout << '\n';
    }
    else cout << "NO" << '\n';
    solve2(n);
    if (ans2[1] != 0) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << ans2[i] << " ";
        }
    }
    else cout << "NO";
}