#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n;
vector <ii> P[Maxn];
int BIT[Maxn];
vector <int> quer[Maxn];
int q;
int L[Maxn], R[Maxn], res[Maxn];
map <ii, int> M;

void Insert(int x, int val)
{
    x++;
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i] += val;
}

int Get(int x)
{
    x++;
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k; scanf("%d", &k);
        P[i].resize(k);
        for (int j = 0; j < k; j++)
            scanf("%d %d", &P[i][j].first, &P[i][j].second);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &L[i], &R[i]); L[i]--; R[i]--;
        quer[L[i]].push_back(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < P[i].size(); j++) {
            int nj = (j + 1) % int(P[i].size());
            int dx = P[i][nj].first - P[i][j].first, dy = P[i][nj].second - P[i][j].second;
            int g = gcd(abs(dx), abs(dy));
            dx /= g; dy /= g;
            map <ii, int>::iterator it = M.find(ii(dx, dy));
            if (it != M.end()) Insert(it->second, -1);
            M[ii(dx, dy)] = i;
            Insert(i, 1);
        }
        for (int j = 0; j < quer[i].size(); j++) {
            int ind = quer[i][j];
            res[ind] = Get(R[ind]);
        }
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}