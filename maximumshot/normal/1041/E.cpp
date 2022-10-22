#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1005;

int n;
int a[N];
int u[N];
int res[N];
int hlp[N];

inline void no() {
    puts("NO");
    exit(0);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int x, y, i = 0;i < n - 1;i++) {
        scanf("%d %d", &x, &y);
        if(x > y) swap(x, y);
        if(y < n) no();
        if(x == n) no();
        a[i] = x;
        u[x] = 1;
    }
    u[n] = 1;

    sort(a, a + n - 1);
    reverse(a, a + n - 1);

//    for(int i = 0;i < n - 1;i++) {
//        cout << a[i] << " ";
//    }
//    cout << "\n";

    int cur = 1;
    res[cur++] = n;

    for(int i = 0;i < n - 1;i++) {
        int j = i;
        while(j < n - 1 && a[j] == a[i]) j++;
        j--;
        int cnt = j - i + 1;
        cur = cur + cnt - 1;
//        cout << "res[ " << cur << " ] = " << a[i] << "\n";
        res[cur] = a[i];
        cur++;
//        cout << "cnt " << cnt << ", " << a[i] << "\n";
        i = j;
    }

    for(int j = n, i = 1;i <= n;i++) {
        if(res[i]) continue;
        while(u[j]) j--;
        u[j] = 1;
        res[i] = j;
    }

    for(int i = n;i >= 1;i--) {
        if(i == n) hlp[i] = res[i];
        else hlp[i] = max(hlp[i + 1], res[i]);
        if(i > 1 && hlp[i] != a[i - 2]) no();
    }

    puts("YES");
    for(int i = 1;i < n;i++) {
        printf("%d %d\n", res[i], res[i + 1]);
    }

    return 0;
}