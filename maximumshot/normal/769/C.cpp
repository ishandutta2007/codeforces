#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1005;

string t = "DLRU";
int di[4] = {1,  0, 0, -1};
int dj[4] = {0, -1, 1,  0};
int n, m, k;
char a[N][N];
int I, J;

void read() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            scanf(" %c", &a[i][j]);
            if(a[i][j] == 'X') {
                I = i;
                J = j;
            }
        }
    }
}

int dist[N][N];

void precalc() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            dist[i][j] = inf;
        }
    }
    dist[I][J] = 0;
    queue< pii > q;
    q.push( {I, J} );
    while(!q.empty()) {
        pii v = q.front();
        q.pop();
        for(int it = 0;it < 4;it++) {
            int i = v.first + di[it];
            int j = v.second + dj[it];
            if(i < 0 || i >= n || j < 0 || j >= m) continue;
            if(a[i][j] == '*') continue;
            if(dist[i][j] > dist[v.first][v.second] + 1) {
                dist[i][j] = dist[v.first][v.second] + 1;
                q.push( {i, j} );
            }
        }
    }
}

string solve() {
    if(k % 2) return "IMPOSSIBLE";
    precalc();
    {
        int ok = 0;
        for(int it = 0;it < 4;it++) {
            int i = I + di[it];
            int j = J + dj[it];
            if(i < 0 || i >= n || j < 0 || j >= m) continue;
            if(a[i][j] == '*') continue;
            ok = 1;
            break;
        }
        if(!ok) return "IMPOSSIBLE";
    }
    string res = "";
    while(k > 0) {
        for(int it = 0;it < 4;it++) {
            int i = I + di[it];
            int j = J + dj[it];
            if(i < 0 || i >= n || j < 0 || j >= m) continue;
            if(a[i][j] == '*') continue;
            if(dist[i][j] < k) {
                res += t[it];
                I = i;
                J = j;
                k--;
                break;
            }
        }
    }
    return res;
}

int main() {

    read();
    cout << solve() << "\n";

    return 0;
}