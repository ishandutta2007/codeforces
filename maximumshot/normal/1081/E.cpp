#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;
const ll MAXX = 1e13;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    vector< ll > a(n + 1);

    for(int x, i = 2;i <= n;i += 2) {
        scanf("%d", &x);
        a[i] = x;
    }

    vector< ll > b(n + 1);

    int ptr = 2;

    for(ll j = 0, i = 1;ptr <= n;i++) {
        if(j < i) j = i;
        if((i + 1) * (i + 1) - i * i > a[ptr]) {
            puts("No");
            return 0;
        }
        while(j * j - i * i < a[ptr]) j++;
        if(j * j - i * i == a[ptr]) {
            b[ptr] = j * j;
            b[ptr - 1] = i * i;
            ptr += 2;
            i = j;
        }
    }

    puts("Yes");

    for(int i = 1;i <= n;i++) {
        printf("%lld ", b[i] - b[i - 1]);
    }

    printf("\n");

    return 0;
}