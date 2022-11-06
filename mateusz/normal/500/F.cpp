#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9, N = 4010, B = 4000, M = 20000;
int n, p, q;
pair<int, pair<int, int> > tab[N];
int prefSack[N][N], sufSack[N][N];
void insert(int *dp, int H, int C) {
    for(int i = B - C; i >= 0; i--) {
        dp[i + C] = max(dp[i + C], dp[i] + H);
    }
}
void compPrefSums(int *dp) {
    for(int i = 1; i <= B; i++) {
        dp[i] = max(dp[i - 1], dp[i]);
    }
}
int getValue(int *dp, int w) {
    return dp[w];
}
void przepisz(int *dp, int *dp2) {
    for(int i = 0; i <= B; i++) {
        dp2[i] = dp[i];
    }       
}
vector<int> crit;
void init() {
    tab[0].first = -30000;
    tab[n + 1].first = 3000000;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= B; j++) {
            prefSack[i][j] = sufSack[i][j] = -INF;
        }
        prefSack[i][0] = sufSack[i][0] = 0;
    }
    crit.push_back(0);
    for(int i = 1; i <= n; i++) {
        if(tab[i].first / p < tab[i + 1].first / p)
            crit.push_back(i);
    }
    for(int i = 0; i < crit.size(); i++) {
        int w = crit[i];
        if(i < crit.size() - 1) {
            for(int j = w + 1; j <= crit[i + 1]; j++) {
                if(j > w + 1) {
                    przepisz(prefSack[j - 1], prefSack[j]);
                }
                insert(prefSack[j], tab[j].second.second, tab[j].second.first);
            }
        }
        if(i == 0) {
            continue;
        }
        for(int j = w; j > crit[i - 1]; j--) {
            if(j < w) {
                przepisz(sufSack[j + 1], sufSack[j]);
            }
            insert(sufSack[j], tab[j].second.second, tab[j].second.first);
        }
    }
    for(int i = 1; i <= n; i++) {
        compPrefSums(prefSack[i]);
        compPrefSums(sufSack[i]);
    }
}
int query(int T, int budget) {
    int L = 0, P = 0;
    for(int i = 1; i <= n; i++) {
        if(tab[i].first <= T && tab[i].first + p - 1 >= T) {
            if(L == 0) {
                L = i;
            }
            P = i;
        }
    }
    if(L > P || L == 0) {
        return 0;
    }
    if(L == P) {
        return tab[L].second.first <= budget? tab[L].second.second: 0;
    }
    if(tab[L].first / p == tab[P].first / p) {
        if(tab[L - 1].first / p == tab[L].first / p) {
            return sufSack[L][budget];
        } else {
            return prefSack[P][budget];
        }
    }
    int ret = 0;
    for(int i = 0; i <= budget; i++) {
        ret = max(ret, prefSack[P][i] + sufSack[L][budget - i]);
    }
    return ret;
}
int main() {
    scanf("%d %d", &n, &p);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", &tab[i].second.first, &tab[i].second.second, &tab[i].first);
    }
    sort(tab + 1, tab + 1 + n);
    init();
    scanf("%d", &q);
    while(q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a, b));
    }
    return 0;
}