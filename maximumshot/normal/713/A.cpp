#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int cnt[1 << 20];

bool solve() {

    int t;
    scanf("%d", &t);

    char ty;
    char s[20];

    for(int n, mask, iter = 0;iter < t;iter++) {
        scanf(" %c %s", &ty, s);
        n = strlen(s);
        mask = 0;
        for(int j = 0, i = n - 1;i >= 0;i--, j++) {
            if((s[i] - '0') % 2) mask |= (1 << j);
        }
        if(ty == '+') cnt[mask]++;
        else if(ty == '-') cnt[mask]--;
        else printf("%d\n", cnt[mask]);
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}