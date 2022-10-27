#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
int ct[205], c[205];
int n, a[nax];
bool has[201];

int solve() {
    scanf("%d", &n);

    fill (has, has + 201, false);

    int ans = 0;

    fill(ct, ct + 201, 0);

    for (int i = 1; i <= n;  ++ i) {
        scanf("%d", a + i);
        ct[a[i]] ++ ;
        has[a[i]] = true;

        ans = max(ans, ct[a[i]]);
    }
    a[n + 1] = 0;



    for (int t = 1 ; t <= 200 ; ++ t) {



        if (ct[t] <= 1) continue;
        int l = -1, r = n + 2;
        int len = -1;
      //  fprintf(stderr, "t %d\n", t);
        fill (c, c + 201, 0);

        while (true) {

      //  fprintf(stderr, "l r %d %d\n", l, r);
        int bef_l = l, bef_r = r;

            ++ len;

            l ++ ; r -- ;
            while (a[l] != t) {
                l ++ ;
            }
            while (a[r] != t) {
                r --;
            }

            if (l >= r) {
                l = bef_l;
                r = bef_r;
                break;
            }
        }

      //  fprintf(stderr, "L R len %d %d %d\n", l,  r, len);

        int mx = 0;


        for (int j = l + 1 ; j < r ; ++ j) {
            c[a[j]] ++ ;
            mx = max(mx, c[a[j]]);
        }

        ans = max(ans, mx + 2 * len);


        while (true) {
            -- len;
            if (len <= 0) break;
            c[a[l]] ++ ;
            mx = max(mx, c[a[l]]);
            l --;

            while (a[l] != t) {
                c[a[l]] ++;
                mx = max(mx, c[a[l]]);
                -- l;
            }

            c[a[r]] ++ ;
            mx = max(mx, c[a[r]]);
            ++ r;

            while (a[r] != t) {
                c[a[r]] ++ ;
                mx = max(mx, c[a[r]]);
                ++ r;
            }

            ans = max(ans, 2 * len + mx);

        }

    }
    return ans;
}

int main () {
    int T;
    for (cin >> T ; T -- ; ) {
        printf("%d\n", solve());
    }
}