#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e3 + 5;

int n, k;
char s[N];
bool can[N][2 * N];

inline void no() {
    puts("NO");
    exit(0);
}

int main() {

    scanf("%d %d %s", &n, &k, s + 1);

    can[0][0 + N] = 1;

    for(int i = 1;i < n;i++) {
        for(int diff = -k + 1;diff <= k - 1;diff++) {
            if(s[i] == 'L') {
                if(diff - 1 > -k) {
                    can[i][diff - 1 + N] |= can[i - 1][diff + N];
                }
            }else if(s[i] == 'W') {
                if(diff + 1 < k) {
                    can[i][diff + 1 + N] |= can[i - 1][diff + N];
                }
            }else if(s[i] == 'D') {
                can[i][diff + N] |= can[i - 1][diff + N];
            }else {
                if(diff - 1 > -k) {
                    can[i][diff - 1 + N] |= can[i - 1][diff + N];
                }
                if(diff + 1 < k) {
                    can[i][diff + 1 + N] |= can[i - 1][diff + N];
                }
                can[i][diff + N] |= can[i - 1][diff + N];
            }
        }
    }

    int i, diff;

    i = n;

    if(s[n] == 'L') {
        if(can[n - 1][-k + 1 + N]) {
            diff = -k;
        }else {
            no();
        }
    }else if(s[n] == 'W') {
        if(can[n - 1][k - 1 + N]) {
            diff = k;
        }else {
            no();
        }
    }else if(s[n] == 'D') {
        no();
    }else {
        if(can[n - 1][-k + 1 + N]) {
            diff = -k;
            s[n] = 'L';
        }else if(can[n - 1][k - 1 + N]) {
            diff = k;
            s[n] = 'W';
        }else {
            no();
        }
    }

    while(i > 0) {
        if(s[i] == '?') {
            if(diff - 1 > -k && can[i - 1][diff - 1 + N]) {
                s[i] = 'W';
            }else if(diff + 1 < k && can[i - 1][diff + 1 + N]) {
                s[i] = 'L';
            }else {
                s[i] = 'D';
            }
        }
        if(s[i] == 'W') {
            diff--;
        }else if(s[i] == 'L') {
            diff++;
        }
        i--;
    }

    printf("%s\n", s + 1);

    return 0;
}