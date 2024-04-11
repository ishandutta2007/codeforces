#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2050;

int m, a[MAXN], b[MAXN], pw10[MAXN];
bitset<2000> num[MAXN];
char s[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    pw10[0] = 1;
    for (int i=1; i<10; i++) pw10[i] = pw10[i-1]*10;

    scanf("%d\n", &m);
    for (int i=0; i<m; i++) {
        scanf("%s\n", s);
        int n = strlen(s);
        reverse(s, s+n);
        memset(a, 0, sizeof(a));
        for (int j=0; j<n; j++)
            a[j/9] += pw10[j%9]*(s[j]-'0');
        int d = 1<<29;
        for (int j=0; j<70; j++) {
            ll cur = 0;
            for (int k=70; k>=0; k--)
                cur = cur*pw10[9]+a[k], a[k] = cur/d, cur %= d;
            for (int k=0; k<29; k++)
                num[j*29+k][i] = bool(cur&1<<k);
        }
    }
/*
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) cout << num[i][j];
        cout << endl;
    }
*/
    for (int i=0, p=0; i<m; i++) {
        int k=-1;
        for (int j=p; j<MAXN; j++)
            if (num[j][i]) {
                k = j; break;
            }
        if (k == -1) continue;
        swap(num[p], num[k]);
        for (int j=p+1; j<MAXN; j++)
            if (num[j][i]) num[j] ^= num[p];
        p++;
    }
/*
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) cout << num[i][j];
        cout << endl;
    }
*/
    memset(b, -1, sizeof(b));
    for (int i=0; i<m; i++) {
        bitset<2000> x;
        bool good = 1;
        for (int j=MAXN-1; j>=0; j--) {
            if (b[j] == -1) {
                if (num[j][i]) good = 0, b[j] = i;
            } else {
                if (((x&num[j]).count()&1) != num[j][i]) x[b[j]] = 1;
            }
        }
        if (!good) printf("0\n");
        else {
            printf("%d ", x.count());
            for (int j=0; j<2000; j++)
                if (x[j]) printf("%d ", j);
            printf("\n");
        }
    }
}