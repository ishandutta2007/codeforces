#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
vector <int> a[nax];
int n;
int match[nax];
int dp[nax][2];
int match_size;
vector <pair <int, int>> matching;
/// dp[i][0] whether vertex i is free or not

void dfs_dp (int nod, int parent) {
    int sum = 0;
    for (int i : a[nod]) {
        if (i == parent) continue;
        dfs_dp(i, nod);
        dp[nod][0] += max(dp[i][1], dp[i][0]);
        sum += max(dp[i][1], dp[i][0]);
    }

    for (int i : a[nod]) {
        if (i == parent) continue;
        dp[nod][1] = max(dp[nod][1], sum - max(dp[i][1], dp[i][0]) + dp[i][0] + 1);
    }

}
void restore (int nod, int parent, int state) {

    if (state == 0) {
        for (int i : a[nod]) {
            if (i != parent) restore(i, nod, dp[i][1] >= dp[i][0] ? 1 : 0);
        }
        return ;
    }

    int sum = 0;
    for (int i : a[nod]) {
        if (i == parent) continue;
        sum += max(dp[i][1], dp[i][0]);
    }

    int mx = 0, nd = -1;

    for (int i : a[nod]) {
        if (i == parent) continue;
        int calc = sum - max(dp[i][1], dp[i][0]) + dp[i][0] + 1;
        if (calc > mx) {
            mx = calc;
            nd = i;
        }
    }

    for (int i : a[nod]) {
        if (i == parent) continue;
        if (i != nd) restore(i, nod, dp[i][1] >= dp[i][0] ? 1 : 0);
        else {
            restore(i, nod, 0);
            match[nod] = nd;
            match[nd] = nod;
            ++ match_size;
            matching.emplace_back(nd, nod);
       //     printf("match %d %d\n", nd, nod);
        }
    }

}

void find_max_match () {
    dfs_dp(1, 0);
    restore(1, 0, dp[1][1] >= dp[1][0] ? 1 : 0);
}

vector <int> to_match[nax];
int answer[nax];

int main () {
    scanf("%d", &n);


    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    find_max_match();
//    printf("%d\n", match_size);
    int ans = 0;
    ans += 2 * match_size;
    int f = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (match[i] == 0) {
            for (int j : a[i]) {
                if (match[j] > 0) {
                    to_match[j].push_back(i);
                    break;
                }
            }
        }
    }

    for (auto &[x, y] : matching) {
        for (int j : to_match[y])
            to_match[x].push_back(j);
        ans += 2 * int(to_match[x].size());
        to_match[x].push_back(x);
        to_match[x].push_back(y);
        int s = to_match[x].size();

        for (int i = 0 ; i < s ; ++ i)
            answer[to_match[x][i]] = to_match[x][(i + 1) % s];
    }

    printf("%d\n", ans);

    for (int i = 1 ; i <= n ; ++ i)
        printf("%d ", answer[i]);
}