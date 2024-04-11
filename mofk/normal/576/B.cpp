#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 1e5 + 5, INF = 1e9;

int n;
int p[MAX];
int id[MAX];
vector <vi> cc(1, vi());

void fail(void) { cout << "NO\n"; }

void init(void) {
    cin >> n;
    ff(i, 1, n) {
        cin >> p[i];
        if (p[i] == i) {
            cout << "YES\n";
            ff(j, 1, n) if (j != i) cout << i << " " << j << "\n";
            exit(0);
        }
    }
}

void process(void) {
    ff(i, 1, n) if (!id[i]) {
        int sz = cc.size();
        id[i] = sz;
        int t = p[i];
        cc.pb(vi(1, i));
        while (t != i) { id[t] = sz; cc.back().pb(t); t = p[t]; }
    }
    int root = 0;
    ff(i, 1, cc.size() - 1) {
        if (cc[i].size() & 1) return fail();
        if (cc[i].size() == 2) root = i;
    }
    if (!root) return fail();
    cout << "YES\n";
    int r1 = 0, r2 = 0;
    ff(i, 1, n) if (id[i] == root) if (r1) r2 = i; else r1 = i;
    ff(i, 1, cc.size() - 1) if (i != root) ff(j, 0, cc[i].size() - 1) if (j & 1) cout << cc[i][j] << " " << r1 << "\n";
    else cout << cc[i][j] << " " << r2 << "\n";
    cout << r1 << " " << r2 << endl;
}

int main(void) {
    init();
    process();
    return 0;
}