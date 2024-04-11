#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 250111, inf = 1000111222;

vector<int> v[max_n];
vector<int> b[max_n];
int n, m, k;
int d[max_n];
bool vis[max_n];
bool leaf[max_n];
int pr[max_n];

int cl = 0;

void dfs(int cur, int dd) {
    d[cur] = dd;
    vis[cur] = 1;
    leaf[cur] = 1;
    for (int to : v[cur]) {
        if (!vis[to]) {
            leaf[cur] = false;
            pr[to] = cur;
            dfs(to, dd + 1);
        } else {
            b[cur].PB(to);
        }
    }
    if (leaf[cur]) ++cl;
}

bool comp(int a, int b) {
    return d[a] < d[b];
}

void printk(int from, int k) {
    int cur = from;
    for (int i = 0; i < k; ++i) {
        printf("%d ", cur + 1);
        cur = pr[cur];
    }
    printf("\n");
}

void print_c(int i) {
    int l2 = d[i] - d[b[i][1]] + 1;
    int l3 = d[i] - d[b[i][2]] + 1;
    if (l2 % 3) {
        printf("%d\n", l2);
        printk(i, l2);
    } else if (l3 % 3) {
        printf("%d\n", l3);
        printk(i, l3);
    } else {
        printf("%d\n", l3 - l2 + 2);
        printf("%d ", i + 1);
        printk(b[i][1], l3 - l2 + 1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    pr[0] = -1;
    dfs(0, 1);
    for (int i = 0; i < n; ++i) {
        sort(b[i].begin(), b[i].end(), comp);
        reverse(b[i].begin(), b[i].end());
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] > d[mx]) {
            mx = i;
        }
    }
    if (d[mx] >= (n + k - 1) / k) {
        cout << "PATH" << endl;
        cout << d[mx] << endl;
        int cur = mx;
        while(true) {
            printf("%d ", cur + 1);
            if (cur == 0) return 0;
            cur = pr[cur];
        }
    }

    if (cl < k) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> cyc;
    for (int i = 0; i < n; ++i) {
        if (!leaf[i]) continue;
        int l2 = d[i] - d[b[i][1]] + 1;
        int l3 = d[i] - d[b[i][2]] + 1;
        if (l2 % 3) {
            cyc.emplace_back(l2, i);
        } else if (l3 % 3) {
            cyc.emplace_back(l3, i);
        } else {
            cyc.emplace_back(l3 - l2 + 2, i);
        }
    }
    sort(cyc.begin(), cyc.end());
    ll s = 0;
    for (int i = 0; i < k; ++i) {
        s += cyc[i].F + 1;
    }
    if (s >= 1e6) {
        exit(228);
    }
    cout << "CYCLES" << endl;
    for (int i = 0; i < k; ++i) {
        print_c(cyc[i].S);
    }
    return 0;
}