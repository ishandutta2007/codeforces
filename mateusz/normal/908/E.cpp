#include <bits/stdc++.h>

using namespace std;

const int N = 1005, M = 1e9 + 7;

int n, m;
int cnk[N][N];
int bell[N];
char line[N];
long long col[N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int mul(int w, int u) {
    return (long long)w * u % M;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    cnk[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cnk[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            add(cnk[i][j], cnk[i - 1][j]);
            add(cnk[i][j], cnk[i - 1][j - 1]);
        }
    }
    
    bell[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            add(bell[i], mul(bell[j], cnk[i - 1][j]));
        }
    } 
    
    for (int i = 1; i <= m; i++) {
        scanf("%s", line);
        for (int j = 0; j < n; j++) {
            col[j] *= 2;
            col[j] += line[j] - '0';
        }
    }
    
    map<long long, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[col[i]]++;
    }
    
    int ans = 1;
    for (const auto &p : cnt) {
        int c = p.second;
        ans = mul(ans, bell[c]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}