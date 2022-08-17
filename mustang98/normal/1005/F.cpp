#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<pair<int, int> > e;
vector<int> v[max_n];
int d[max_n];
int n, m, k, outp = 0;
ll cank = 1;
bool take[max_n];

void bfs() {
    memset(d, -1, sizeof(d));
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); ++i) {
            int to = v[cur][i];
            if (d[to] != -1) continue;
            d[to] = d[cur] + 1;
            q.push(to);
        }
    }
}

vector<int> ed[max_n];

void rec(int cur) {
    if (cur == n) {
        for (int i = 0; i < m; ++i) {
            printf("%d", take[i]);
        }
        printf("\n");
        outp++;
        if (outp == cank) {
            exit(0);
        }
        return;
    }
    for (int i = 0; i < ed[cur].size(); ++i) {
        for (int j = 0; j < ed[cur].size(); ++j) {
            take[ed[cur][j]] = 0;
        }
        take[ed[cur][i]] = 1;
        rec(cur + 1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
        e.PB(MP(a, b));
    }
    bfs();
    for (int i = 0; i < m; ++i) {
        if (d[e[i].F] > d[e[i].S]) {
            swap(e[i].F, e[i].S);
        }
    }
    for (int i = 0; i < m; ++i) {
        int f = e[i].F;
        int t = e[i].S;
        if (d[f] == d[t]) continue;
        ed[t].PB(i);
    }
    for (int i = 1; i < n; ++i) {
        cank *= ed[i].size();
        if (cank > k) {
            cank = k;
            break;
        }
    }
    cout << cank << endl;
    rec(1);

    return 0;
}