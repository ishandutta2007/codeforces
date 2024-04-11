#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
char s[nax];
int n;
int t[nax];
int z[nax];
int o[nax];
int u[nax];
vector <int> disappear[nax];
int nxt[nax];

int get_nxt (int x) {
    return nxt[x] == x ? x : nxt[x] = get_nxt(nxt[x]);
}

int main () {

    scanf("%d%s", &n, s + 1);

    for (int i = 1 ; i <= n ; ++ i) {
        z[i] += z[i - 1];
        o[i] += o[i - 1];
        u[i] += u[i - 1];
        if (s[i] == '1') ++ o[i];
        else if (s[i] == '0') ++ z[i];
        else if (s[i] == '?') ++ u[i];
    }

    for (int i = 1 ; i <= n;  ++ i) {
        int l = 1, r = n - i + 1;
        while (l <= r) {
            int mid = l + r >> 1;
            int ct_zero = z[i + mid - 1] - z[i - 1];
            int ct_one = o[i + mid - 1] - o[i - 1];
            int ct_qs = u[i + mid - 1] - u[i - 1];

            if (max(ct_zero, ct_one) + ct_qs == mid) {
                t[i] = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
    }

    for (int i = n ; i >= 1 ; -- i) {
        disappear[t[i] + 1].push_back(i);
    }
    for (int i = 0 ; i <= n + 1; ++ i) {
        nxt[i] = i;
    }


    for (int i = 1 ; i <= n ; ++ i) {
        for (int j : disappear[i]) {
            nxt[j] = j + 1;
        }


        int f = get_nxt(1);
        if (f == n + 1) {
            printf("0 ");
            continue;
        }
        int ct = 1;

        while (true) {
            int to = f + i;
            if (to > n) break;
            int g = get_nxt(to);
            if (g > n) break;
            ++ ct;
            f = g;
        }
        printf("%d ", ct);
    }
    puts("");

   /* for (int i = 1 ; i <= n;  ++ i)
        printf("%d ", nxt[i]);
    puts("");*/
}