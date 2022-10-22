#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop() {
    LL N; cin >> N;
    int ans = 0;
    for (int i = 1; i <= 30; i++) {
        LL nx = (1ll << i) - 1;
        nx = (nx + 1) * nx / 2;
        if (N < nx) break;
        N -= nx; ans++;
    }
    printf("%d\n", ans);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) loop();
    return 0;
}