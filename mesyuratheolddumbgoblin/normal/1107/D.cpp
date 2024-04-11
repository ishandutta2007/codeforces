#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll, ll>
typedef int ll;
int Abs(int x) {
    return x>0?x:-x;
}

ll n, a[5205][5205], b[5205][5205], k;
char s[5000];
ll to_n(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    return c + 10 - 'A';
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);

        for (int j = 0; j < n/4; j++) {
            ll tm = to_n(s[j]);
            for (int k = 0; k < 4; k++) {
                a[i+1][1+j*4 + k] = ((tm>>(3-k))&1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        if (n % i == 0) {
            bool flag = true;
            for (int j = 0; j < n/i; j++)
            for (int k = 0; k < n/i; k++) {
                ll sum = b[j*i+i][k*i+i] - b[j*i][k*i+i] - b[j*i+i][k*i] + b[j*i][k*i];
                if (sum == i*i || sum == 0) {

                } else {
                    flag = false;
                }
            }
            if (flag) {
                cout << i << endl;
                return 0;
            }

        }

    }
    return 0;
}