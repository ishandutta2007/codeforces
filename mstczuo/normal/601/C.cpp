# include <bits/stdc++.h>

using namespace std;

double E[1000000+10];
double S[1000000+10];

int n, m, s, a[120];

int main() {
    //freopen("in","r",stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), s += a[i];
    if(n == 1) { printf("%d\n",a[1]); return 0; }
    if(m == 1) { printf("%d\n", 1); return 0; }
    for(int i = 1; i <= m; ++i) if(i != a[1]) E[i] = 1. / (m - 1);
    for(int i = 2; i <= n; ++i) {
        S[0] = 0;
        for(int j = 1; j <= (i + 1) * m; ++j) S[j] = S[j-1] + E[j];
        for(int j = 1; j <= (i + 1) * m; ++j)
            E[j] = (S[j - 1] - S[max(0, j - m - 1)]) / (m - 1) - 
                (S[max(0, j - a[i])] - S[max(0, j - a[i] - 1)]) / (m - 1);
    }

    double ans = 0;
    for(int j = n; j < s; ++j) ans += E[j];
    printf("%.10lf\n", 1 + ans * (m-1));
}