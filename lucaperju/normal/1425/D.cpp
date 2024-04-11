#include <bits/stdc++.h>

using namespace std;

const int N = 2e3, MX = 1000;


int n, m, r;

const long long mod=1000000007;
long long comb[2003][2003];
void chestie ()
{
    comb[1][1]=comb[1][0]=1;
    comb[0][0]=1;
    for(int i=2;i<=2000;++i)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;++j)
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod;
    }
}

struct Drept {
    int x1;
    int y1;
    int x2;
    int y2;
};
int sum[1 + MX][1 + MX];
int x[1 + N], y[1 + N];
long long danger[1 + N];
Drept intersect (Drept a, Drept b) {
    Drept c;
    c.x1 = max (a.x1, b.x1);
    c.y1 = max (a.y1, b.y1);
    c.x2 = min (a.x2, b.x2);
    c.y2 = min (a.y2, b.y2);
    return c;
}

int get (Drept a) {
    a.x1 = max (a.x1, 1);
    a.x2 = min (a.x2, MX);
    a.y1 = max (a.y1, 1);
    a.y2 = min (a.y2, MX);
    return sum[a.x2][a.y2] - sum[a.x2][a.y1 - 1] - sum[a.x1 - 1][a.y2] + sum[a.x1 - 1][a.y1 - 1];
}

int main () {

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> danger[i];
        sum[x[i]][y[i]]++;
    }
    chestie ();
    for (int i = 1; i <= MX; i++)
        for (int j = 1; j <= MX; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    using ll = long long;
    ll ans = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            /**
            n= total -nu loveste (a)-nu loveste (b)+nu loveste (a,b)
            nu loveste (i) = C(n - k, m)
            **/
            ll total = comb[n][m];
            Drept A = {x[a] - r, y[a] - r, x[a] + r, y[a] + r};
            Drept B = {x[b] - r, y[b] - r, x[b] + r, y[b] + r};
            Drept AB = intersect (A, B);

            int kA = get (A);
            int kB = get (B);
            int kAB;
            if (AB.x1 > AB.x2 || AB.y1 > AB.y2)
                kAB = 0;
            else
                kAB = get (AB);
            ll notHitA = comb[n - kA][m];
            ll notHitB = comb[n - kB][m];
            int k = kA + kB - kAB;
            ll notHitAB = comb[n - k][m];
            ll n = (total - notHitA - notHitB + notHitAB + 1ll * 2 * mod) % mod;
            ans = (ans + n * 2 % mod * danger[a] % mod * danger[b]) % mod;
        }
    }
    for (int a = 1; a <= n; a++) {
        ll total = comb[n][m];
        Drept A = {x[a] - r, y[a] - r, x[a] + r, y[a] + r};
        int kA = get (A);
        ll notHitA = comb[n - kA][m];
        ll n = (total - notHitA + mod) % mod;
        ans = (ans + n * danger[a] % mod * danger[a]) % mod;
    }
    cout << ans << "\n";
    return 0;
}