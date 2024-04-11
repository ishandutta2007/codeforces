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

int n ,m , k;
int d[max_n];
int dd[max_n];
vector<int> v[max_n];
vector<int> good;
queue<int> q;

bool cmp(int a, int b) {
    if (d[a] != d[b]) {
        return d[a] < d[b];
    }
    if (dd[a] != dd[b]) {
        return dd[a] > dd[b];
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        --a;
        good.PB(a);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    for (int i = 0; i < max_n; ++i) {
        d[i] = inf;
    }
    d[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : v[cur]) {
            if (d[to] > d[cur] + 1) {
                d[to] = d[cur] + 1;
                q.push(to);
            }
        }
    }
    ///////////////////////////////
    for (int i = 0; i < max_n; ++i) {
        dd[i] = inf;
    }
    dd[n - 1] = 0;
    q.push(n - 1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : v[cur]) {
            if (dd[to] > dd[cur] + 1) {
                dd[to] = dd[cur] + 1;
                q.push(to);
            }
        }
    }
    //////////////////////////
    sort(good.begin(), good.end(), cmp);
    int mx_sp = -1;
    int prmx = d[good[0]];
    for (int i = 1; i < good.size(); ++i) {
        int cur = good[i];
        mx_sp = max(mx_sp, prmx + 1 + dd[cur]);
        prmx = max(prmx, d[cur]);
    }
    int ans = min(mx_sp, d[n - 1]);
    cout << ans << endl;
    return 0;
}