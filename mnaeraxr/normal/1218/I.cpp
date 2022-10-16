#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

vector<string> readBoard(int n){
    vector<string> board(n);

    for (int i = 0; i < n; ++i)
        cin >> board[i];

    return board;
}

void fail(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<string> A = readBoard(n);
    vector<string> B = readBoard(n);
    string x; cin >> x;

    vector<int> color(2 * n, -1);
    vector<vector<pii>> adj(2 * n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            if (x[i] == '0'){
                if (x[j] == '0'){
                    if (A[i][j] != B[i][j])
                        fail();
                } else {
                    if (A[i][j] == B[i][j])
                        color[i] = 0;
                    else
                        color[i] = 1;
                }
            } else {
                if (x[j] == '0'){
                    if (A[i][j] == B[i][j])
                        color[j + n] = 0;
                    else
                        color[j + n] = 1;
                } else {
                    if (A[i][j] == B[i][j]){
                        adj[i].push_back(pii(j + n, 0));
                        adj[j + n].push_back(pii(i, 0));
                    } else {
                        adj[i].push_back(pii(j + n, 1));
                        adj[j + n].push_back(pii(i, 1));
                    }
                }
            }
        }

    // for (int i = 0; i < 2 * n; ++i){
    //     cout << i << " " << color[i] << " " << adj[i].size() << endl;
    // }

    vector<bool> visited(2 * n);

    auto assert_valid = [&](int u, int v, int p){
        if (color[u] == -1 || color[v] == -1)
            return;

        if ((color[u] ^ color[v]) != p)
            fail();
    };

    auto bfs = [&](int s){
        queue<int> q; q.push(s);
        visited[s] = true;

        while (!q.empty()){
            int u = q.front(); q.pop();

            for (auto e : adj[u]){
                int v = e.first;
                int p = e.second;

                assert_valid(u, v, p);

                if (!visited[v]){
                    visited[v] = true;
                    color[v] = color[u] ^ p;
                    q.push(v);
                }
            }
        }
    };

    // First pass
    for (int i = 0; i < 2 * n; ++i){
        if (!visited[i] && color[i] >= 0){
            bfs(i);
        }
    }

    for (int i = 0; i < 2 * n; ++i){
        if (!visited[i]){
            assert(color[i] == -1);
            color[i] = 0;
            bfs(i);
        }
    }

    vector<int> answer;

    for (int i = 0; i < 2 * n; ++i){
        assert(color[i] >= 0);
        if (color[i] > 0)
            answer.push_back(i);
    }

    cout << answer.size() << endl;

    for (auto x : answer){
        if (x < n)
            cout << "row " << x << endl;
        else
            cout << "col " << x - n << endl;
    }

    return 0;
}