#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int64 mod = 1000000007;
const int64 mod2 = 2 * mod;

struct mat{
    int64 M[2][2];

    mat operator *(const mat &a) const{
        mat ans;

        ans.M[0][0] = (M[0][0] * a.M[0][0] + M[0][1] * a.M[1][0]) % mod2;
        ans.M[0][1] = (M[0][0] * a.M[0][1] + M[0][1] * a.M[1][1]) % mod2;
        ans.M[1][0] = (M[1][0] * a.M[0][0] + M[1][1] * a.M[1][0]) % mod2;
        ans.M[1][1] = (M[1][0] * a.M[0][1] + M[1][1] * a.M[1][1]) % mod2;

        return ans;
    }
};

mat matexp(mat A, int64 p){
    if (p == 1) return A;
    if (p & 1) return A * matexp(A, p - 1);
    return matexp(A * A, p / 2);
}

int64 modexp(int64 a, int64 p){
    if (p == 1) return a;
    if (p & 1) return a * modexp(a, p - 1) % mod2;
    return modexp(a * a % mod2, p / 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int k; cin >> k;

    mat A;

    A.M[0][0] = 0, A.M[0][1] = 1, A.M[1][0] = 2, A.M[1][1] = 1;

    int64 den = 2;

    for (int i = 0; i < k; ++i){
        int64 p; cin >> p;
        A = matexp(A, p);
        den = modexp(den, p);
    }

    cout << A.M[0][0] / 2 << "/" << den / 2 << endl;

    return 0;
}