#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int cnt[2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        cnt[0] = cnt[1] = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            cnt[a % 2]++;
        }
        printf("%d\n", n - max(cnt[0], cnt[1]));
    }
    return 0;
}