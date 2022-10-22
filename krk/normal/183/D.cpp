#include <bits/stdc++.h>
using namespace std;

typedef pair <double, int> di;
 
using cd = complex<double>;
const double PI = acos(-1);
const int Maxn = 3005;
const int Maxm = 305;
 
int n, m;
double prob[Maxn][Maxm];
double dp[Maxn];
double ex[Maxm][Maxn];
int pnt[Maxm];
 
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
 
vector<double> multiply(vector<double> const& a, vector<double> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<double> result(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i].real();
    while (!result.empty() && result.back() < 1e-12l) result.pop_back();
    return result;
}
 
vector <double> Get(int l, int r, int ind)
{
    if (l == r) return {double(1.0) - prob[l][ind], prob[l][ind]};
    else {
        int m = l + r >> 1;
        return multiply(Get(l, m, ind), Get(m + 1, r, ind));
    }
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int num; scanf("%d", &num);
            prob[i][j] = double(num) / 1000;
        }
    for (int j = 0; j < m; j++) {
        auto cur = Get(0, n - 1, j);
        double sump = 0, sumex = 0;
        for (int i = 0; i <= n; i++) {
            if (i < cur.size()) {
                sump += cur[i];
                sumex += cur[i] * i;
            }
            ex[j][i] = sumex + (1.0 - sump) * i;
        }
    }
    priority_queue <di> Q;
    for (int j = 0; j < m; j++) {
        Q.push(di(ex[j][1], j));
        pnt[j] = 1;
    }
    double res = 0;
    for (int i = 0; i < n; i++) {
        di v = Q.top(); Q.pop();
        res += v.first;
        pnt[v.second]++;
        Q.push(di(ex[v.second][pnt[v.second]] - ex[v.second][pnt[v.second] - 1], v.second));
    }
    cout << fixed << setprecision(12) << res << endl;
    return 0;
}