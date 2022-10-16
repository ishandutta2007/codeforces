#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M;
vi adj[100005];
int lab[100005];

int main(void) {
    cin >> N >> M;
    int u, v;
    ff(i, 1, M) {
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    queue <int> q;
    ff(r, 1, N) if (!lab[r]) {
        q.push(r); lab[r] = 1;
        while (!q.empty()) {
            u = q.front(); q.pop();
            ff(i, 0, (int)adj[u].size() - 1) {
                v = adj[u][i];
                if (lab[v] == lab[u]) return cout << -1 << endl, 0;
                if (!lab[v]) {
                    lab[v] = 3 - lab[u];
                    q.push(v);
                }
            }
        }
    }
    vi A, B;
    ff(i, 1, N) if (lab[i] == 1) A.pb(i); else B.pb(i);
    cout << A.size() << "\n";
    ff(i, 0, (int)A.size() - 1) cout << A[i] << " "; cout << "\n";
    cout << B.size() << "\n";
    ff(i, 0, (int)B.size() - 1) cout << B[i] << " "; cout << "\n";
    return 0;
}