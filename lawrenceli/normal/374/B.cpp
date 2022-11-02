#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n, cur;
ll ans = 1;
bool b[MAXN];
char str[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%s", str); n = strlen(str);
    for (int i=0; i<n-1; i++) {
        if (str[i]+str[i+1]-2*'0' == 9) b[i] = 1;
    }
    for (int i=0; i<n; i++) {
        if (b[i]) cur++;
        else if (cur) {
            if (!(cur & 1)) ans *= cur/2 + 1;
            cur = 0;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}