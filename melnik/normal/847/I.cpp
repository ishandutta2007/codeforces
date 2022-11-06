#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

struct node {
    int x, y, len;
    node(int _x, int _y, int _len) {
        x = _x;
        y = _y;
        len = _len;
    }

    node() {}
};

struct que {
    node t[3000];
    int f, s;
    que () {
        f = 0, s = 0;
    }
    void add(int x, int y, int len) {
        t[f++] = node(x, y, len);
    }
    node get() {
        return t[s++];
    }
    int empty() {
        if(f == s)return 1; else return 0;
    }
};

int p1[4] = {1, -1, 0, 0};
int p2[4] = {0, 0, 1, -1};

int cnt = 0;
int t[251][251], used[251][251];
ll ans[251][251];
ll n, m, p, k;
que q;

void make(int x, int y, int val) {
    cnt++;
    q.f = 1, q.s = 0;
    q.add(x, y, val);
    while(!q.empty()) {
        node v = q.get();
       // cout << v.x << ' ' << v.y << ' ' << v.len << endl;
        used[v.x][v.y] = cnt;
        ans[v.x][v.y] += (ll)v.len;
        for(int i = 0; i < 4; i++) {
            int qx = v.x + p1[i];
            int qy = v.y + p2[i];
            if(t[qx][qy] == -1 || qx == 0 || qy == 0 || qx == n + 1 || qy == m + 1) continue;
            if(used[qx][qy] == cnt || (v.len / 2) == 0) continue;
            used[qx][qy] = cnt;
            q.add(qx, qy, v.len / 2);
        }
    }
}

int main() {
    cin >> n >> m >> k >> p;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if(c == '*') {
                t[i][j] = -1;
            } else {
                if(c != '.') {
                    t[i][j] = c - 'A' + 1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(t[i][j] >= 1)
                make(i, j, t[i][j] * k);
                /*for(int i1= 1; i1 <= n; i1++) {
                    for(int j1 = 1; j1 <= m; j1++) {
                        cout << ans[i1][j1] << ' ';
                    }
                    cout << endl;
                }
                cout << "!!!!!!!!!!!!\n";
                memset(ans, 0, sizeof(ans));*/
        }
    }
    int tmp = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(ans[i][j] > p) {
                tmp++;
            }
        }
    }
    cout << tmp;
}