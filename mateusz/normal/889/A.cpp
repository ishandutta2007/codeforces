#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, x;
int num[N], last[N];

int main() {
    
    last[0] = 1;
    num[0] = 1;
    scanf("%d", &n);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (last[num[x]] == x) {
            num[i] = num[x];
        } else {
            num[i] = ++ans;
        }
        last[num[i]] = i;
    }
    
    printf("%d\n", ans);
    
    return 0;
}