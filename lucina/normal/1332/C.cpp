#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
char s[nax];
int n, k;
vector<int> a[nax];
bool vis[nax];


void solve () {
    scanf("%d %d", &n, &k);
    scanf("%s", s);

    for (int i = k ; i < n;  ++ i) {
        a[i].push_back(i % k);
        a[i % k].push_back(i);
      //  printf("%d %d\n", i, i % k);
    }

    for (int i = 0 ; i < n ; ++ i) {
        int v = n - i - 1;
        if (i != v) {
            a[i].push_back(v);
            a[v].push_back(i);
           // printf("%d %d\n", i, v);
        }
    }

    vector<char> st;

    fill(vis, vis + n, false);

    function<void (int)> dfs = [&] (int nod) -> void {
        vis[nod] = true;
        st.push_back(s[nod]);
        for (int i : a[nod]) {
            if (!vis[i])
                dfs(i);
        }
    };

    int ans = 0;

    for (int i = 0 ; i < n; ++ i) {
        if (vis[i]) continue;
        st.clear();
        dfs(i);
        sort(st.begin(), st.end());
/*
        printf("huh\n");
        for (char c : st)
            printf("%c", c);
        printf("\n");*/

        int res = 0;

        for (int j = 0 ; j < (int)st.size() ; ++ j) {
            int v = j;
            while (v < (int)st.size() && st[v] == st[j]) ++ v;
            res = max(res, v - j);
            j = v - 1;
        }

        ans += (int)st.size() - res;
    }

    printf("%d\n", ans);
}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ;) {
        solve();

        for (int i = 0 ; i <= n ; ++ i)
            a[i].clear();
    }
}
/*
    Good Luck
        -Lucina
*/