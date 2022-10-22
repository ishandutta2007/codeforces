#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 55;

char mat[N][N];
int col[N][N];
int n, m, k;
int sz = 0;

void dfs(int i, int j) {
    col[i][j] = sz;
    for(int di = -1;di <= 1;di++) {
        for(int dj = -1;dj <= 1;dj++) {
            if(di && dj || !di && !dj) continue;
            int toi = i + di;
            int toj = j + dj;
            if(toi < 1 || toi > n || toj < 1 || toj > m) continue;
            if(mat[toi][toj] == '*' || col[toi][toj] != -1) continue;
            dfs(toi, toj);
        }
    }
}

bool solve() {
    
    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> mat[i][j];
            col[i][j] = -1;
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(mat[i][j] == '*' || col[i][j] != -1) continue;
            dfs(i, j);
            sz++;
        }
    }

    vec< pii > mas;

    for(int cl = 0;cl < sz;cl++) {
        int ok = 1;
        for(int i = 1;i <= n;i++) {
            if(col[i][1] == cl) ok = 0;
            if(col[i][m] == cl) ok = 0;
        }
        for(int j = 1;j <= m;j++) {
            if(col[1][j] == cl) ok = 0;
            if(col[n][j] == cl) ok = 0;
        }
        if(!ok) continue;
        int Cnt = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(col[i][j] == cl) Cnt++;
            }
        }
        mas.push_back({Cnt, cl});
    }

    sort(ALL(mas));
    int tot = (int)mas.size();
    int res = 0;

    for(int iter = 0;iter < (int)mas.size() && tot > k;iter++, tot--) {
        int cl = mas[iter].second;
        res += mas[iter].first;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(col[i][j] == cl)
                    mat[i][j] = '*';
            }
        }
    }

    cout << res << '\n';
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cout << mat[i][j];
        }
        cout << '\n';
    }

    cout << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}