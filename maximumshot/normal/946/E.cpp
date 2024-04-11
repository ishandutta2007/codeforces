#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;
const double pi = acos(-1.0);

const int L = 4e5 + 5;

char s[L];
int n;

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int mask = 0;
    for(int i = 1;i <= n;i++) {
        mask ^= (1 << (s[i] - '0'));
    }
    for(int i = n;i >= 1;i--) {
        mask ^= (1 << (s[i] - '0'));
        for(char c = s[i] - 1;c >= (i == 1 ? '1' : '0');c--) {
            int tmp = mask ^ (1 << (c - '0'));
            int nd = __builtin_popcount(tmp);
            if(nd <= n - i) {
                for(int q = 1;q < i;q++) {
                    printf("%c", s[q]);
                }
                printf("%c", c);
                for(int q = 0;q < n - i - nd;q++) {
                    printf("9");
                }
                for(int x = 9;x >= 0;x--) {
                    if((1 << x) & tmp) {
                        printf("%d", x);
                    }
                }
                printf("\n");
                return;
            }
        }
    }
    for(int i = 0;i < n - 2;i++) {
        printf("9");
    }
    printf("\n");
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int t;

    scanf("%d", &t);

    while(t--) {
        solve();
    }

    return 0;
}