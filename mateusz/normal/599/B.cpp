#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
int a[N], b[N], f[N];
int where[N];
bool amb[N];

int main() {

    scanf("%d %d", &n, &m);

    bool amb1 = false;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
        if (where[f[i]] != 0) {
            amb[f[i]] = true;
        }
        where[f[i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        if (where[b[i]] == 0) {
            printf("Impossible\n");
            return 0;
        }
        if (amb[b[i]]) {
            amb1 = true;
        }
        a[i] = where[b[i]];
    }

    if (amb1 == true) {
        printf("Ambiguity\n");
    } else {
        printf("Possible\n");
        for (int i = 1; i <= m; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}