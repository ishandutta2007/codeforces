#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int cnt[26];
int n, k;
char c;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 0;i < n;i++) {
        scanf(" %c", &c);
        cnt[c - 'a']++;
    }

    if(*max_element(cnt, cnt + 26) <= k) {
        puts("YES");
    }else {
        puts("NO");
    }

    return 0;
}