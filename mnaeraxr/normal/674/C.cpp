#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int maxk = 50;

struct rect{
    ld m, n;
    ld eval(ld x){
        return m * x + n;
    }

    ld intersect(rect r){
        return (r.n - n) / (m - r.m);
    }
};

struct cht
{
    vector<rect> hull;
    int beg, end;

    cht(int mx){
        beg = end = 0;
        hull = vector<rect>(mx);
    }

    int size(){
        return end - beg;
    }

    void add(rect r){
        while (size() > 1){
            ld x1 = r.intersect(hull[end - 1]);
            ld x2 = r.intersect(hull[end - 2]);
            if (x2 > x1) --end;
            else break;
        }
        hull[end++] = r;
    }

    ld eval(ld x){
        if (!size()) return 1e60;

        while (size() > 1 && hull[beg].eval(x) > hull[beg + 1].eval(x))
            ++beg;

        return hull[beg].eval(x);
    }
};

ld V[maxn];
ld A[maxn];
ld B[maxn];
ld dp[maxk][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    dp[0][1] = 1e60;
    for (int i = 1; i <= n; ++i){
        ld v; cin >> v;
        V[i] = V[i - 1] + v;
        A[i] = A[i - 1] + V[i] / v;
        B[i] = B[i - 1] + (ld)1.0 / v;
        dp[1][i] = A[i];
    }

    for (int j = 2; j <= k; ++j){
        cht CH(n);

        dp[j][0] = 1e60;
        for (int i = 1; i <= n; ++i){
            dp[j][i] = min((ld)1e60, CH.eval(B[i]) + A[i]);
            CH.add({-V[i], V[i] * B[i] + dp[j - 1][i] - A[i]});
        }
    }

    cout.precision(17);
    cout << fixed << dp[k][n] << endl;

    return 0;
}