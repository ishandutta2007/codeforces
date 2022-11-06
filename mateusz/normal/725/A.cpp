#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
char word[N];
bool taken[N];

int main() {

    scanf("%d", &n);
    scanf("%s", &word[1]);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (word[i] == '>') {
            break;
        }
        taken[i] = true;
        ans++;
    }

    for (int i = n; i >= 1; i--) {
        if (word[i] == '<' || taken[i]) {
            break;
        }
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}