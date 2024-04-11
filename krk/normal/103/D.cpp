#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

struct query {
       int a, b, id;
};

int n, c;
ll w[Maxn];
int p;
query raids[Maxn];
ll dp[Maxn], dpfor;
ll res[Maxn];

bool Less(const query &a, const query &b)
{
    if (a.b != b.b) return a.b < b.b;
    return a.a < b.a;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n; c = int(sqrt(double(n)) + 0.5);
    for (int i = 1; i <= n; i++) cin >> w[i];
    cin >> p;
    for (int i = 0; i < p; i++) {
        cin >> raids[i].a >> raids[i].b;
        raids[i].id = i;
    }
    sort(raids, raids + p, Less);
    dpfor = 0;
    for (int i = 0; i < p; i++)
       if (raids[i].b == dpfor) res[raids[i].id] = dp[raids[i].a];
       else if (raids[i].b > c) {
               ll sum = 0;
               for (int j = raids[i].a; j <= n; j += raids[i].b)
                  sum += w[j];
               res[raids[i].id] = sum;
       } else {
              dpfor = raids[i].b;
              for (int j = n; j >= raids[i].a; j--)
                 if (j + raids[i].b > n) dp[j] = w[j];
                 else dp[j] = w[j] + dp[j + raids[i].b];
              res[raids[i].id] = dp[raids[i].a];
       }
    for (int i = 0; i < p; i++)
       cout << res[i] << endl;
    return 0;
}