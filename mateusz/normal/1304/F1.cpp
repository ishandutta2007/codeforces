#include <bits/stdc++.h>

using namespace std;

const int N = 55, M = 20005;

int n, m, k;

long long pref[N][M], dp[N][M], tab[N][M], suf[N][M];

long long momentDod[M];
long long takeSum(int day, int from, int to) {
    return tab[day][min(m, to)] - tab[day][from - 1];
}

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &tab[i][j]);
            tab[i][j] += tab[i][j - 1];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        dp[1][i] = takeSum(1, i, i + k - 1) + takeSum(2, i, i + k - 1);
        pref[1][i] = max(pref[1][i - 1], dp[1][i]);
    }
    for (int i = m; i >= 1; i--) {
        suf[1][i] = max(suf[1][i + 1], dp[1][i]);
    }

    for (int i = 2; i <= n; i++) {
        deque<pair<int, long long>> Q;
        for (int j = 1; j <= min(k, m - k + 1); j++) {
            long long myValue = dp[i - 1][j] - takeSum(i, j, k);
            while (!Q.empty() && Q.back().second < myValue) {
                Q.pop_back();
            }
            Q.push_back({j, myValue});
        }
        dp[i][1] = max(Q.front().second, suf[i - 1][k + 1]) + takeSum(i, 1, k) + takeSum(i + 1, 1, k);
        long long toAddQ = 0, toAddQ2 = 0;
        deque<pair<int, long long>> Q2;
        for (int j = 2; j + k - 1 <= m; j++) {
            while (!Q2.empty() && Q2.front().first + k - 1 < j) {
                Q2.pop_front();
            }
            if (!Q.empty() && Q.front().first < j) {
                int pos = Q.front().first;
                long long value = Q.front().second + toAddQ;
                Q.pop_front();
            }
            int pos = j - 1;
            long long value = dp[i - 1][j - 1] - takeSum(i, j - 1, j + k - 2); 
            while (!Q2.empty() && Q2.back().second < value - toAddQ2) {
                Q2.pop_back();
            }
            Q2.push_back({pos, value - toAddQ2});
            
            toAddQ2 += takeSum(i, j - 1, j - 1);
            
            value = dp[i - 1][j + k - 1];
            while (!Q.empty() && Q.back().second < value + toAddQ) {
                Q.pop_back();
            }
            momentDod[j + k - 1] = value;
            Q.push_back({j + k - 1, value + toAddQ});
            toAddQ += takeSum(i, j + k - 1, j + k - 1);
            assert(!Q.empty() && !Q2.empty());
             dp[i][j] = max(max(Q.front().second - toAddQ, Q2.front().second + toAddQ2), max(pref[i - 1][j - k], suf[i - 1][j + k])) + takeSum(i, j, j + k - 1) + takeSum(i + 1, j, j + k - 1);
        }
        for (int j = 1; j <= m; j++) {
            pref[i][j] = max(pref[i][j - 1], dp[i][j]);
        }
        for (int j = m; j >= 1; j--) {
            suf[i][j] = max(suf[i][j + 1], dp[i][j]);
        }
    }
    

    printf("%lld\n", pref[n][m - k + 1]);
    
    return 0;
}