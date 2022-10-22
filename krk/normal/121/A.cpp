#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll l, r;
vector <ll> V;
ll res;

void Gen(int lvl, ll num)
{
     if (lvl) V.push_back(num);
     if (lvl == 10) return;
     Gen(lvl + 1, 10LL * num + 4LL);
     Gen(lvl + 1, 10LL * num + 7LL);
}

int main()
{
    Gen(0, 0); sort(V.begin(), V.end());
    scanf("%I64d %I64d", &l, &r);
    int i = 0;
    while (V[i] < l) i++;
    while (l <= r) {
          res += V[i] * min(r - l + 1LL, V[i] - l + 1LL);
          l = V[i] + 1;
          i++;
    }
    printf("%I64d\n", res);
    return 0;
}