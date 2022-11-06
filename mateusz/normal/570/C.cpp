#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, m, pos;
char word[N], c;

int calcResult() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (word[i] == '.' && word[i + 1] == '.') {
            ret++;
        }
    }
    return ret;
}

int main() {

    scanf("%d %d", &n, &m);

    scanf("%s", &word[1]);

    int ans = calcResult();

    while (m--) {
        scanf("%d %c", &pos, &c);
        if ((word[pos] != '.' && c != '.') || (word[pos] == '.' && c == '.')) {
            printf("%d\n", ans);
            continue;
        }
        if (c == '.') {
            if (word[pos - 1] == '.') {
                ans++;
            }
            if (word[pos + 1] == '.') {
                ans++;
            }
        } else {
            if (word[pos - 1] == '.') {
                ans--;
            }
            if (word[pos + 1] == '.') {
                ans--;
            }
        }
        word[pos] = c;
        printf("%d\n", ans);
    }
    return 0;
}