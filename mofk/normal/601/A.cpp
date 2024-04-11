#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int MAX = 405;

int N, M;
bool a[MAX][MAX];
int d[MAX];

int main(void) {
    cin >> N >> M;
    int u, v;
    ff(i, 1, M) {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    if (a[1][N]) ff(i, 1, N) ff(j, 1, N) if (i != j) a[i][j] ^= 1;
    ff(i, 2, N) d[i] = 99999;
    queue <int> q;
    q.push(1);
    while (!q.empty()) {
        u = q.front(); q.pop();
        ff(i, 1, N) if (a[u][i] && d[i] == 99999) {
            d[i] = d[u] + 1;
            q.push(i);
        }
    }
    if (d[N] == 99999) cout << -1 << endl; else cout << d[N] << endl;
    return 0;
}