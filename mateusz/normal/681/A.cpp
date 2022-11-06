#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
char name[N];
int start, finish;

int main() {

    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s %d %d", &name[1], &start, &finish);
        if (start >= 2400 && finish > start) {
            ans++;
        }
    }
    printf(ans > 0 ? "YES\n" : "NO\n");

    return 0;
}