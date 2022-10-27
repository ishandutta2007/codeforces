#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 3;
int const C = 300;
int f[nax * C + nax];
int n;
int pref[nax];
char s[nax];
long long ans;
int one[nax];

long long naive () {

    long long ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        int ct = 0;
        for (int j = i; j <= n ; ++ j) {
            if (s[j] == '1') ct ++;
            if (ct > 0 && (j - i + 1) % ct == 0) ++ ans;
        }
    }

    return ans;
}


int main(){
    scanf("%s", s + 1);

    n = strlen(s + 1);


    for (int i = 1 ; i <= n ; ++ i) {
        pref[i] = pref[i - 1] + (s[i] == '1');
    }

    f[n] = 1;

    for (int k = 1 ; k <= C ; ++ k) {


        for (int i = 1 ; i <= n ; ++ i) {
            int buf = k * pref[i] - i + n;
            ans += f[buf] ++;
        }
        for (int i = 1 ; i <= n ; ++ i) {
            int buf = k * pref[i] - i + n;
            -- f[buf];
        }
    }

  ///  printf("%lld\n", ans);
    int m = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (s[i] == '1') one[++ m] = i;
    }


    /// const int bound = n / C;

    int cur = 1;

    for (int i = 1 ; i <= n ; ++ i) {

        while (cur <= m && one[cur] < i) ++ cur;

        if (cur > m) break;

        for (int c = 1 ; cur + c - 1 <= m ; ++ c) {

            int l = i + c * (C + 1) - 1;
            l = max(l, one[cur + c - 1]);
            if (l > n) break;

            int r = (cur + c - 1 == m ? n + 1 : one[cur + c]) - 1;

            if (l <= r) {
             ///   printf("l r c %d %d %d\n", l, r , c);
                /// count number in range [l, r]
                /**
                such that
                (x - i + 1) (mod c) == 0
                Look like a distance
                */
             /*   for (int j = l ; j <= r ; ++ j) {
                    if ((j - i + 1) % c == 0) ++ ans;
                }
                */
                int dist1 = l - i + 1, dist2 = r - i + 1;
                ans += (dist2) / c - ((dist1 - 1) / c); //?
            }
        }
    }

    printf("%lld\n", ans);

}
/*
    Good Luck
        -Lucina
*/