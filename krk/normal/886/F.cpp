#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
 
const int Maxn = 2005;
 
ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }
 
struct frac {
    ll a, b;
    frac(ll ga = 0ll, ll gb = 1ll) {
        if (gb < 0) { ga = -ga; gb = -gb; }
        a = ga; b = gb;
    }
    void Fix() {
        ll g = gcd(abs(a), b);
        a /= g; b /= g;
    }
    bool operator<(const frac &f) const {
        return a * f.b < f.a * b;
    }
    bool operator==(const frac &f) const {
        return a * f.b == f.a * b;
    }
    frac operator-(const frac &f) const {
        return frac(a * f.b - f.a * b, b * f.b);
    }
    frac operator+(const frac &f) const {
        return frac(a * f.b + f.a * b, b * f.b);
    }
    frac operator*(const frac &f) const {
        return frac(a * f.a, b * f.b);
    }
    frac operator/(const frac &f) const {
        return frac(a * f.b, b * f.a);
    }
    frac operator*(const ll mult) const {
        return frac(a * mult, b);
    }
};
 
int n;
int X[Maxn], Y[Maxn];
frac Xc, Yc;
int all;
set <frac> valid;
bool hasValid;
 
bool Check(const frac &k, ll s)
{
    frac C = (Xc * k) + (Yc * s);
    C.Fix();
    vector <frac> A, B;
    for (int i = 0; i < n; i++) {
        frac me = (k * X[i]) + (s * Y[i]);
        auto sub = me - C;
        sub.Fix();
        if (sub.a == 0) continue;
        if (sub.a > 0) A.push_back(sub);
        else {
            sub.a = -sub.a;
            B.push_back(sub);
        }
    }
    if (A.size() != B.size()) return false;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < A.size(); i++)
        if (!(A[i] == B[i])) return false;
    return true;
}
 
int main()
{
    scanf("%d", &n);
    ll sumX = 0, sumY = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        sumX += X[i];
        sumY += Y[i];
    }
    Xc = frac(sumX, n);
    Yc = frac(sumY, n);
    Xc.Fix();
    Yc.Fix();
    for (int i = 0; i < n; i++) {
        set <frac> S;
        bool any = false;
        for (int j = 0; j < n && !any; j++) {
            frac A = ((frac(Y[i], 1) + frac(Y[j], 1)) - (Yc * 2));
            frac B = (Xc * 2) - (frac(X[i], 1) + frac(X[j], 1));
            if (B.a == 0) {
                if (A.a == 0) any = true;
            } else {
                frac C = A / B;
                C.Fix();
                S.insert(C);
            }
        }
        if (any) all++;
        else if (!hasValid) {
            valid = S;
            hasValid = true;
        } else for (auto it = valid.begin(); it != valid.end(); )
            if (S.find(*it) == S.end()) valid.erase(it++);
            else it++;
    }
    if (all == n) printf("-1\n");
    else {
        int res = Check(frac(1, 1), 0);
        for (auto k: valid)
            res += Check(k, 1);
        printf("%d\n", res);
    }
    return 0;
}