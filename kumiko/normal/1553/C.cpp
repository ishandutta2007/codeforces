#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

int T;
char s[11], t[11];

int solve(int x) {
    int w[2] = {0, 0}, re[2] = {5, 5};
    for (int i = 0; i < 10; ++i) {
        if (s[i] == '1')
            ++w[i & 1];
        else if (s[i] == '?' && (i & 1) == x)
            ++w[i & 1];
        --re[i & 1];
        if (re[x ^ 1] + w[x ^ 1] < w[x]) return i + 1;
    }
    return 10;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        printf("%d\n", min(solve(0), solve(1)));
    }
    return 0;
}