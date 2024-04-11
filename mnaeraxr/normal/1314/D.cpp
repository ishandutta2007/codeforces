#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>

#define endl '\n'

using namespace std;

const int maxn = 80;

long long mat[maxn][maxn];
long long len[maxn][maxn][6];
long long who[maxn][maxn][6];

void insert(int x, int y, int w, int v, int t) {
    if (t < 6) {
        len[x][y][t] = v;
        who[x][y][t] = w;
    } else {
        if (v < len[x][y][5]) {
            len[x][y][5] = v;
            who[x][y][5] = w;
        }
        t = 5;
    }
    while (t > 0 && len[x][y][t] < len[x][y][t - 1]) {
        swap(len[x][y][t], len[x][y][t - 1]);
        swap(who[x][y][t], who[x][y][t - 1]);
        t--;
    }
}

long long answer = 1000000000000000000;

int n, k;
int path[8];
int cnt[maxn];

void go(int s, int c) {
    if (c + 1 == k) {
        long long cur = 0;

        for (int i = 0; i < k; ++i) {
            int u = path[i], v = path[i + 1];
            int t = 0;
            while (t < n && cnt[who[u][v][t]]) t++;
            if (t == n) return;
            cur += len[u][v][t];
        }

        answer = min(answer, cur);

    } else {
        for (int i = 0; i < n; ++i) {
            path[c + 1] = i;
            cnt[i]++;
            go(i, c + 1);
            cnt[i]--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    k /= 2;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t = 0;
            for (int p = 0; p < n; ++p) {
                if (p == i || p == j)
                    continue;
                insert(i, j, p, mat[i][p] + mat[p][j], t++);
            }
        }
    }

    cnt[0]++;
    go(0, 0);    

    cout << answer << endl;

    return 0;
}