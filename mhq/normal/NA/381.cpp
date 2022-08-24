#include <bits/stdc++.h>
using namespace std;
int n;
int dx[3] = {1, -1, 0};
int dy[3] = {1, -1, 0};
int ax, ay, bx, by;
const int maxN = 1005;
bool used[maxN][maxN];
bool bad(int a, int b) {
    if (a < 1 || a > n || b < 1 || b > n) return true;
    if (a == ax || b == ay) return true;
    if ((a + b) == (ax + ay)) return true;
    if ((a - b) == (ax - ay)) return true;
    return false;
}
void dfs(int x, int y) {
    used[x][y] = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x1 = dx[i];
            int y1 = dy[j];
            if (x1 == 0 && y1 == 0) continue;
            if (bad(x + x1, y + y1)) continue;
            if (used[x + x1][y + y1]) continue;
            dfs(x + x1, y + y1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> ax >> ay >> bx >> by;
    dfs(bx, by);
    int cx, cy;
    cin >> cx >> cy;
    if (used[cx][cy]) cout << "YES";
    else cout << "NO";
}