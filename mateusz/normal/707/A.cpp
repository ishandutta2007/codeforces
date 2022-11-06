#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
char x;

int main() {

    bool color = false;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &x);
            if (x == 'C' || x == 'M' || x == 'Y') {
                color = true;
            }
        }
    }

    printf(color ? "#Color\n" : "#Black&White");
    return 0;
}