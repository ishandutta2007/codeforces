#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

vector<int> v[max_n];
char f[max_n];
int n;
bool val[max_n];
bool ans[max_n];
bool res[max_n];

bool dfs(int cur) {
    if (v[cur].size() == 0) {
        res[cur] = val[cur];
        return val[cur];
    }
    if (v[cur].size() == 1) {
        res[cur] = !dfs(v[cur][0]);
        return res[cur];
    }
    bool l = dfs(v[cur][0]);
    bool r = dfs(v[cur][1]);
    if (f[cur] == 'A') {
        res[cur] = l & r;
        return l & r;
    }
    if (f[cur] == 'O') {
        res[cur] = l | r;
        return l | r;
    }
    if (f[cur] == 'X') {
        res[cur] = l ^ r;
        return l ^ r;
    }
}

void dfs2(int cur) {
    ans[cur] = !ans[cur];
    if (v[cur].size() == 0) return;
    if (v[cur].size() == 1) {
        dfs2(v[cur][0]);
        return;
    }

    int l = v[cur][0], r = v[cur][1];
    bool rl = res[l], rr = res[r];
    if (f[cur] == 'A') {
        if (((!rl) & rr) != res[cur]) dfs2(l);
        if ((rl & (!rr)) != res[cur]) dfs2(r);
    }
    if (f[cur] == 'O') {
        if (((!rl) | rr) != res[cur]) dfs2(l);
        if ((rl | (!rr)) != res[cur]) dfs2(r);
    }
    if (f[cur] == 'X') {
        if (((!rl) ^ rr) != res[cur]) dfs2(l);
        if ((rl ^ (!rr)) != res[cur]) dfs2(r);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    char s[5];
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int l, r;
        f[i] = s[0];
        if (s[0] == 'I') {
            scanf("%d", &val[i]);
            continue;
        } else if (s[0] == 'N') {
            scanf("%d", &l);
            --l;
            v[i].PB(l);
        } else {
            scanf("%d %d", &l, &r);
            --l, --r;
            v[i].PB(l);
            v[i].PB(r);
        }
    }
    bool init = dfs(0);
    for (int i = 0; i < n; ++i) {
        ans[i] = init;
    }
    dfs2(0);
    for (int i = 0; i < n; ++i) {
        if (v[i].size() == 0) {
            printf("%d", ans[i]);
        }
    }


    return 0;
}