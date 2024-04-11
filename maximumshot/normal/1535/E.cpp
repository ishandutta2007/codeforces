#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 20;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    struct Node {
        int a = 0;
        int c = 0;
        vector<int> p = vector<int>(LOG, -1);
    };

    int a0, c0;
    cin >> a0 >> c0;

    vector<Node> t = {Node{a0, c0, vector<int>(LOG, -1)}};

    for (int it = 0; it < q; it++) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int P, A, C;
            cin >> P >> A >> C;
            Node node = {A, C, vector<int>(LOG, -1)};
            node.p[0] = P;
            for (int j = 1; j < LOG; j++) {
                int pv = node.p[j - 1];
                if (pv == -1) node.p[j] = -1;
                else node.p[j] = t[pv].p[j - 1];
            }
            t.push_back(node);
        } else {
            t.emplace_back();
            int V, W;
            cin >> V >> W;
            ll suma = 0;
            ll sumac = 0;
            while (W > 0) {
                int x = V;
                for (int j = LOG - 1; j >= 0; j--) {
                    int px = t[x].p[j];
                    if (px == -1 || t[px].a == 0) continue;
                    x = px;
                }
                if (t[x].a == 0) break;
                ll mn = min(W, t[x].a);
                t[x].a -= mn;
                W -= mn;
                suma += mn;
                sumac += mn * t[x].c;
            }
            cout << suma << " " << sumac << endl;
        }
    }

    return 0;
}