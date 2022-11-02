#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;

int N, K;
char mat[maxn][maxn];
int cmp[maxn][maxn], csze[maxn * maxn], ccnt;

void dfs(int r, int c) {
    cmp[r][c] = ccnt;
    csze[ccnt]++;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if ((dr == 0) ^ (dc == 0)) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < N && nc >= 0 && nc < N && mat[nr][nc] == '.' && cmp[nr][nc] == -1)
                    dfs(nr, nc);
            }
}

int sum, freq[maxn * maxn];

void upd(int i, int j, int v) {
    int c = cmp[i][j];
    freq[c] += v;
    if (v == -1 && freq[c] == 0) sum -= csze[c];
    else if (v == 1 && freq[c] == 1) sum += csze[c];
}

void upd0(int i, int j, int v) {
    if (mat[i][j] == '.')
        upd(i, j, v);
}

void upd2(int sr, int sc, int v) {
    if (sr > 0) {
        for (int i = sc; i < sc + K; i++)
            upd0(sr - 1, i, v);
    }

    if (sr + K < N) {
        for (int i = sc; i < sc + K; i++)
            upd0(sr + K, i, v);
    }

    if (sc > 0) {
        for (int i = sr; i < sr + K; i++)
            upd0(i, sc - 1, v);
    }

    if (sc + K < N) {
        for (int i = sr; i < sr + K; i++)
            upd0(i, sc + K, v);
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> mat[i];

    memset(cmp, -1, sizeof(cmp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cmp[i][j] == -1) {
                if (mat[i][j] == 'X') {
                    cmp[i][j] = ccnt;
                    csze[ccnt++] = 1;
                } else {
                    dfs(i, j);
                    ccnt++;
                }
            }
            //cout << csze[cmp[i][j]] << ' ';
        }
        //cout << endl;
    }


    int ans = 0;
    for (int sr = 0; sr + K <= N; sr++) {
        memset(freq, 0, sizeof(freq));
        sum = 0;
        for (int i = sr; i < sr + K; i++)
            for (int j = 0; j < K; j++)
                upd(i, j, 1);

        for (int j = 0; j + K <= N; j++) {
            upd2(sr, j, 1);
            ans = max(ans, sum);
            upd2(sr, j, -1);
            if (j + K == N) continue;
            for (int i = sr; i < sr + K; i++) {
                upd(i, j, -1);
                upd(i, j + K, 1);
            }
        }
    }

    cout << ans << '\n';
}