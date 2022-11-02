#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;

int n, l[MAXN], r[MAXN];

double p(int i, int a) {
    if (l[i] > a) return 0;
    if (r[i] <= a) return 1;
    return double(a-l[i]+1)/(r[i]-l[i]+1);
}

double p2(int i, int a) {
    if (r[i] < a) return 0;
    if (l[i] > a) return 0;
    return 1./(r[i]-l[i]+1);
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
    }

    double ans = 0;
    for (int i=1; i<=10000; i++) {
        double sum = 0;
        for (int j=0; j<n; j++) {
            double x = 1, y = 1;
            for (int k=0; k<n; k++)
                if (j!=k)
                    x *= p(k, i), y *= p(k, i-1);
            x -= y;
            x *= 1-p(j, i);
            sum += x;
        }

        for (int j=0; j<1<<n; j++)
            if (__builtin_popcount(j) > 1) {
                double x = 1;
                for (int k=0; k<n; k++)
                    if (j&1<<k) x *= p2(k, i);
                    else x *= p(k, i-1);
                sum += x;
            }

        ans += sum * i;
    }

    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}