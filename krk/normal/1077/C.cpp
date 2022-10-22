#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

map <ll, int> M;
int n;
int a[Maxn];
ll sum;
vector <int> res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        M[a[i]]++;
    }
    for (int i = 1; i <= n; i++) if ((sum - a[i]) % 2 == 0) {
        ll nd = (sum - a[i]) / 2;
        if (nd == a[i] && M[nd] > 1 || nd != a[i] && M.find(nd) != M.end())
            res.push_back(i);
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}