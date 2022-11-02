#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 4010;
const int MAXV = 36100;

int a, n, pre[MAXN];
ll ans;
char s[MAXN];
int freq[MAXV];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %s", &a, s); n = strlen(s);
    for (int i=0; i<n; i++) pre[i+1] = pre[i] + s[i] - '0';
    for (int i=0; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            freq[pre[j] - pre[i]] ++;
        }
    }
    if (a == 0) {
        ans += ll(freq[0]) * freq[0];
        for (int i=1; i<MAXV; i++) ans += 2 * ll(freq[0]) * freq[i];
    } else {
        for (int i=1; i<MAXV; i++) {
            if (a % i != 0) continue;
            if (a / i < MAXV) ans += ll(freq[i]) * freq[a / i];
        }
    }
    printf("%I64d\n", ans);
    return 0;
}