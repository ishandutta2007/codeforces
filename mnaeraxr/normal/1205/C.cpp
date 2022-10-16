#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;
 
bool ask(int x1, int y1, int x2, int y2){
    x1++; y1++; x2++; y2++;
 
    assert(x1 <= x2);
    assert(y1 <= y2);
    assert(x1 + y1 + 2 <= x2 + y2);
 
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();
 
    int x; cin >> x;
    return x == 1;
}
 
pii get_prev(int x, int y){
    y -= 2;
 
    while (y < 0){
        y++;
        x--;
    }
 
    return pii(x, y);
}
 
struct disjoint_set{
    vector<int> ds;
 
    disjoint_set(int n){
        ds = vi(n, -1);
    }
 
    int root(int a){
        return ds[a] < 0 ? a : ds[a] = root(ds[a]);
    }
 
    bool join(int a, int b){
        a = root(a);
        b = root(b);
        if (a == b) return false;
 
        if (ds[a] < ds[b]) swap(a, b);
        ds[b] += ds[a];
        ds[a] = b;
        return true;
    }
};
 
vector<int> make_color(vector<vector<pii>> &graph){
    vector<int> col(graph.size(), -1);
 
    col[0] = 0;
    deque<int> q;
    q.push_back(0);
 
    while (!q.empty()){
        int u = q.front(); q.pop_front();
 
        for (auto e : graph[u]){
            if (col[e.first] >= 0)
                continue;
 
            if (e.second){
                col[e.first] = 1 - col[u];
                q.push_back(e.first);
            } else {
                col[e.first] = col[u];
                q.push_front(e.first);
            }
        }
    }
 
    for (auto x : col)
        assert(x >= 0);
 
    return col;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
 
    vector<vi> ans(n, vi(n, -1));
    ans[0][0] = 1;
    ans[n - 1][n - 1] = 0;
 
    for (int d = 2; d < 2 * (n - 1); d += 2){
        int y = 0; int x = d - y;
 
        if (x >= n){
            x = n - 1;
            y = d - x;
        }
 
        while (true){
            pii z = get_prev(x, y);
 
            if (ask(z.first, z.second, x, y))
                ans[x][y] = ans[z.first][z.second];
            else
                ans[x][y] = 1 - ans[z.first][z.second];
 
            x--;
            y++;
 
            if (x < 0 || y >= n) break;
        }
    }
 
    // cout << "HERE" << endl; cout.flush();
 
    int tot = 0;
 
    vector<vi> ix(n, vi(n, -1));
 
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if ((i + j) & 1){
                ix[i][j] = tot++;
            }
        }
    }
 
    vector<vector<pii>> graph(tot);
    vector<int> col(tot);
 
    // cout << "HERE" << endl; cout.flush();
 
    for (int d = 3; d < 2 * (n - 1); d += 2){
        int y = 0; int x = d - y;
 
        if (x >= n){
            x = n - 1;
            y = d - x;
        }
 
        while (true){
            pii z = get_prev(x, y);
 
            // cout << x << " " << y << " " << z.first << " " << z.second << endl;
 
            int a = ix[z.first][z.second];
            int b = ix[x][y];
 
            // cout << a << " " << b << endl; cout.flush();
 
            assert(a >= 0);
            assert(b >= 0);
 
            if (ask(z.first, z.second, x, y)){
                graph[a].push_back(pii(b, 0));
                graph[b].push_back(pii(a, 0));
            }
            else{
                graph[a].push_back(pii(b, 1));
                graph[b].push_back(pii(a, 1));
            }
 
            x--;
            y++;
 
            if (x < 0 || y >= n) break;
        }
    }
 
    // cout << "HERE" << endl; cout.flush();
 
    int a = ix[0][1];
    int b = ix[1][2];
    if (ask(0, 1, 1, 2)){
        graph[a].push_back(pii(b, 0));
        graph[b].push_back(pii(a, 0));
    } else {
        graph[a].push_back(pii(b, 1));
        graph[b].push_back(pii(a, 1));
    }
    // cout << "HERE" << endl; cout.flush();
 
    vector<int> colors = make_color(graph);
 
    // exit(0);
 
    bool looking = true;
    int zero = -1;
 
    for (int i = 0; i < n && looking; ++i)
        for (int j = 0; j < n && looking; ++j){
            if ((i + j) & 1) continue;
 
            map<int,vector<pii>> a, b;
 
            for (int s = -1; s <= 1; s += 2){
                for (int dx = 0; dx <= 2; ++dx){
                    int dy = 2 - dx;
 
                    int x = i + s * dx;
                    int y = j + s * dy;
 
                    int px = dx ? x - s : x;
                    int py = dx ? y : y - s;
 
                    if (0 <= x && x < n && 0 <= y && y < n)
                        a[ans[x][y]] = {pii(px, py), pii(x, y)};
                }
                a.swap(b);
            }
 
            for (int c = 0; c < 2 && looking; ++c){
                if (a.find(c) != a.end() && b.find(1 - c) != b.end()){
                    looking = false;
 
                    auto A = a[c];
                    auto B = b[1 - c];
 
                    int ixa = ix[A[0].first][A[0].second];
                    int ixb = ix[B[0].first][B[0].second];
 
                    if (colors[ixa] == colors[ixb]){
                        if (ans[A[1].first][A[1].second] == ans[i][j]){
                            bool res = ask(A[1].first, A[1].second, B[0].first, B[0].second);
                            zero = colors[ixa] ^ ans[i][j] ^ (int)res ^ 1;
                        } else {
                            bool res = ask(A[0].first, A[0].second, B[1].first, B[1].second);
                            zero = colors[ixb] ^ ans[i][j] ^ (int)res ^ 1;
                        }
                    } else {
                        if (ans[A[1].first][A[1].second] != ans[i][j]){
                            bool res = ask(A[1].first, A[1].second, B[0].first, B[0].second);
                            zero = colors[ixa] ^ ans[i][j] ^ (int)res ^ 1;
                        } else {
                            bool res = ask(A[0].first, A[0].second, B[1].first, B[1].second);
                            zero = colors[ixb] ^ ans[i][j] ^ (int)res ^ 1;
                        }
                    }
                }
            }
        }
 
    cout << "!" << endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (ans[i][j] < 0){
                int p = ix[i][j];
                cout << (colors[p] ^ zero);
            } else
            cout << ans[i][j];
        }
        cout << endl;
    }
    cout.flush();
 
    return 0;
}