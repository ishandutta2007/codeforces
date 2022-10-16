#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
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

int n, k;
vector <vi> v;
int next[MAX];

void init(void) {
    cin >> n >> k;
    v.assign(k + 1, vi());
    ff(i, 1, k) {
        int m; cin >> m;
        ff(j, 1, m) { int x; cin >> x; v[i].pb(x); }
    }
}

void process(void) {
    ff(i, 1, k) {
        for (int j = 0; j + 1 < v[i].size(); j++) next[v[i][j]] = v[i][j+1];
    }
    ff(i, 1, n) if (next[i] != i + 1) {
        int cnt = 0;
        ff(j, i, n) if (next[j]) cnt++;
        cout << n - i + cnt << endl; return;
    }
}

int main(void) {
    init();
    process();
    return 0;
}