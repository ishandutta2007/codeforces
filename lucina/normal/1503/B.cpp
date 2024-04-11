#include<bits/stdc++.h>
using namespace std;
int get_other(int x, int y) {
    return 6 - x - y;
}
int n;
queue <pair <int, int>> q[2];
void place(int i, int j, int col) {
    cout << col << ' ' << i << ' ' << j  << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= n ; ++ j)
        q[(i + j) % 2].emplace(i, j);
    int x;
    cin >> x;
    int nx = (x + 1) % 3 + 1;
    place(q[0].front().first, q[0].front().second, nx);
    q[0].pop();
    int y;
    cin >> y;
    int ny = nx != y ? get_other(nx, y) : (y + 1) % 3 + 1;
    place(q[1].front().first, q[1].front().second, ny);
    q[1].pop();
    assert(nx != ny);
    while (!q[0].empty() && !q[1].empty()) {
        int col;
        cin >> col;
        if (col != nx) {
            place(q[0].front().first, q[0].front().second, nx);
            q[0].pop();
        } else if (col != ny) {
            place(q[1].front().first, q[1].front().second, ny);
            q[1].pop();
        } else assert(false);
    }
    while (!q[0].empty()) {
        int col;
        cin >> col;
        for (int i = 1 ; i <= 3 ; ++ i)
            if (i != col && i != ny) {
                place(q[0].front().first, q[0].front().second, i);
                q[0].pop();
                break;
            }
    }
    while (!q[1].empty()) {
        int col;
        cin >> col;
        for (int i = 1 ; i <= 3 ; ++ i)
            if (i != col && i != nx) {
                place(q[1].front().first, q[1].front().second, i);
                q[1].pop();
                break;
        }
    }
}