#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m;
int A[N];
int S[N], size;
priority_queue<pair<int, int> > QMAX, QMIN;
int ans[N], mon[N], r[N];
bool isSet[N];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        QMAX.push({A[i], i});
        QMIN.push({-A[i], i});
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &mon[i], &r[i]);
        while(size > 0 && r[S[size]] <= r[i]) {
            size--;
        }
        S[++size] = i;
    }

    int x = r[S[1]];
    for (int i = n; i >= x + 1; i--) {
        ans[i] = A[i];
        isSet[i] = true;
    }

    S[size + 1] = 0;

    for (int i = 1; i <= size; i++) {
        int w = S[i];
        int prev = r[S[i + 1]];
        if (mon[w] == 1) {
            for (int j = r[w]; j > prev; j--) {
                while (!QMAX.empty() && isSet[QMAX.top().second]) QMAX.pop();
                int pos = QMAX.top().second;
                ans[j] = QMAX.top().first;
                isSet[pos] = true;
                QMAX.pop();
            }
        } else {
            for (int j = r[w]; j > prev; j--) {
                while (!QMIN.empty() && isSet[QMIN.top().second]) QMIN.pop();
                int pos = QMIN.top().second;
                ans[j] = -QMIN.top().first;
                isSet[pos] = true;
                QMIN.pop();
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}