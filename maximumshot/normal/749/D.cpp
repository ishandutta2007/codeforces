#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n, k;
int a[N];
int b[N];
int l[N];
bool used[N];
vec< int > pos[N];

bool check(int p) {
    int tot = 0;
    for(int i = 0;i < k;i++) {
        tot += pos[ l[i] ].end() - lower_bound( ALL( pos[ l[i] ] ), p);
    }
    return tot == n - p + 1;
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &a[i], &b[i]);
        used[a[i]] = 1;
        pos[ a[i] ].push_back( i );
    }

    int total = 0;
    for(int i = 1;i <= n;i++) total += used[i];

    int q;

    scanf("%d", &q);

    for(int iter = 0;iter < q;iter++) {
        scanf("%d", &k);
        int tot = 0;
        for(int i = 0;i < k;i++) {
            scanf("%d", &l[i]);
            if(!used[l[i]]) continue;
            tot++;
        }
        if(tot == total) {
            puts("0 0");
            continue;
        }
        int bl = 1;
        int br = n;
        int bm;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(check(bm)) br = bm;
            else bl = bm + 1;
        }

        int where = ( bl < br && check(bl) ? bl - 1 : ( check(br) ? br - 1 : n ) );
        int who = a[ where ];

        printf("%d ", who);
        l[k++] = who;

        bl = 1;
        br = n;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(check(bm)) br = bm;
            else bl = bm + 1;
        }

        where = ( bl < br && check(bl) ? bl : br );

        if( where == 1 ) {
            printf("%d\n", b[ pos[who][0] ] );
        }else {
            int first = *upper_bound( ALL( pos[who] ), where - 1 );
            printf("%d\n", b[ first ]);
        }
    }

    return 0;
}