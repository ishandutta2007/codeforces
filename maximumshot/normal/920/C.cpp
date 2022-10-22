#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 2e5 + 5;

int n;
int a[N];
char s[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    scanf("%s", s + 1);

    for(int i = 1;i <= n;i++) {
        int j = i;
        while(j < n && s[j] == '1') j++;
        // i .. j
        sort(a + i, a + j + 1);
        for(int q = i;q <= j;q++) {
            if(a[q] != q) {
                puts("NO");
                return 0;
            }
        }
        i = j;
    }

    puts("YES");

    return 0;
}