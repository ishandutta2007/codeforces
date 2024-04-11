#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m, occ;
pair<long long, int> S[N], pom[N], T[N];
char c;
vector<int> occurences;
int size;
int P[N];

void KMP() {
    P[0] = -1;
    int t = -1;
    for (int i = 1; i <= m; i++) {
        while (t >= 0 && S[t + 1] != S[i]) t = P[t];
        t++;
        P[i] = t;
    }
    int i = 0, j = 0;
    while (i <= n - m) {
        while (j < m && S[j + 1] == T[i + j + 1]) j++;
        if (j == m) occurences.push_back(i + 1);
        i = i + j - P[j];
        j = max(0, P[j]);
    }
}

int main() {

    scanf("%d %d", &n, &m);

    int size = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d-%c", &occ, &c);
        if (size > 0 && T[size].second == c) {
            T[size].first += occ;
            continue;
        } else {
            T[++size] = {occ, c};
        }
    }

    n = size;
    size = 0;

    for (int i = 1; i <= m; i++) {
        scanf("%d-%c", &occ, &c);
        if (size > 0 && pom[size].second == c) {
            pom[size].first += occ;
            continue;
        } else {
            pom[++size] = {occ, c};
        }
    }

    if (size == 1) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (T[i].second == pom[1].second)
                ans += max(0LL, T[i].first - pom[1].first + 1);
        }
        printf("%I64d\n", ans);
        return 0;
    }

    for (int i = 2; i < size; i++) {
        S[i - 1] = pom[i];
    }

    m = size - 2;
    size = 0;

    KMP();

    int ans = 0;
    for (int i = 0; i < occurences.size(); i++) {
        int w = occurences[i];
        if (w > 1 && w <= n - m && T[w - 1].second == pom[1].second && T[w - 1].first >= pom[1].first && T[w + m].second == pom[m + 2].second && T[w + m].first >= pom[m + 2].first) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}