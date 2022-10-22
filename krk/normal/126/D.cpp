#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll lim = 1000000000000000000LL;

vector <ll> F;
int t;
ll n;

ll Ways()
{
    vector <int> s;
    int ind = lower_bound(F.begin(), F.end(), n) - F.begin();
    for (int i = ind; i >= 0; i--)
        if (n >= F[i]) { n -= F[i]; s.push_back(i); }
    s.push_back(-1);
    ll dp1[2], dp2[2];
    dp1[0] = 1; dp2[0] = 0;
    for (int i = s.size() - 2; i >= 0; i--) {
        dp1[1] = dp1[0] + dp2[0];
        dp2[1] = ll((s[i] - s[i + 1] - 1) / 2) * dp1[0] + ll((s[i] - s[i + 1]) / 2) * dp2[0];
        dp1[0] = dp1[1]; dp2[0] = dp2[1]; 
    }
    return dp1[0] + dp2[0];
}

int main()
{
    F.push_back(1); F.push_back(2);
    while (F[F.size() - 2] + F[F.size() - 1] <= lim)
          F.push_back(F[F.size() - 2] + F[F.size() - 1]);
    scanf("%d", &t);
    while (t--) {
          scanf("%I64d", &n);
          printf("%I64d\n", Ways());
    }
    return 0;
}