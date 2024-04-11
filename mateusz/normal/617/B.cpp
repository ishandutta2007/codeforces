#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n;
int tab[N];
long long ans;

int main() {

    ans = 1;
    scanf("%d", &n);

    int last = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        if (tab[i] == 1) {
            if (last != -1) {
                ans *= (i - last);
            }
            last = i;
        }
    }

    if (last == -1) {
        printf("0\n");
        return 0;
    }
    
    printf("%I64d\n", ans);
    return 0;
}