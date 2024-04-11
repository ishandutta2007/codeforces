#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
long long t, a[N], b[N];
int x[N];
int pref[N];
bool cant[N];

int main() {
    
    scanf("%d %lld", &n, &t);
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        b[i] = max(b[i], a[i] + t);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        if (x[i] < i) {
            printf("No\n");
            return 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        pref[i]++;
        pref[x[i]]--;
        cant[x[i]] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
        if (pref[i] > 0) {
            b[i] = a[i + 1] + t;
        }
        b[i] = max(b[i], b[i - 1] + 1);
        if (cant[i] && i + 1 <= n && b[i] >= a[i + 1] + t) {
            printf("No\n");
            return 0;
        }
    }
    
    printf("Yes\n");
    for (int i = 1; i <= n; i++) {
        printf("%lld ", b[i]);
    }
    
    return 0;
}