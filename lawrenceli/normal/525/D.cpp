#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2005;

int n, m, num[MAXN][MAXN];
char mat[MAXN][MAXN];

bool w(int r, int c) { return mat[r][c] == '*'; }

stack<pii> stk;

void upd(int r, int c) {
    mat[r][c] = '.';
    for (int dr=-1; dr<=0; dr++)
        for (int dc=-1; dc<=0; dc++) {
            int nr = r+dr, nc = c+dc;
            if (nr >=0 && nc >= 0) {
                num[nr][nc]--;
                if (num[nr][nc] == 1) stk.push(pii(nr, nc));
            }
        }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> mat[i];
    for (int i=0; i<n-1; i++)
        for (int j=0; j<m-1; j++)
            num[i][j] = w(i, j) + w(i+1, j) + w(i, j+1) + w(i+1, j+1);
    
    for (int i=0; i<n-1; i++)
        for (int j=0; j<m-1; j++)
            if (num[i][j] == 1)
                stk.push(pii(i, j));
    
    while (!stk.empty()) {
        int r = stk.top().first, c = stk.top().second;
        stk.pop();
        for (int dr=0; dr<2; dr++)
            for (int dc=0; dc<2; dc++) {    
                int nr = r+dr, nc = c+dc;
                if (w(nr, nc)) upd(nr, nc);
            }
    }
    
    for (int i=0; i<n; i++) cout << mat[i] << '\n';
}