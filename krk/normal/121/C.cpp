#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 15;

vector <ll> V;
int n, k;
int en;
bool taken[Maxn];
int perm[Maxn];
int res;

void Gen(int lvl, ll num)
{
     if (lvl) V.push_back(num);
     if (lvl == 9) return;
     Gen(lvl + 1, 10LL * num + 4LL);
     Gen(lvl + 1, 10LL * num + 7LL);
}

ll Fac(int x)
{
    ll res = 1;
    while (x) res *= ll(x--);
    return res;
}

int getPerm(int x)
{
    ll f = Fac(x);
    for (int i = 0; i < x; i++) {
        f /= ll(x - i);
        int j;
        for (j = 0; j < x; j++) if (!taken[j])
            if (f < k) k -= f;
            else break;
        perm[i] = j; taken[j] = true;
    }
}

bool Lucky(int x)
{
     while (x) {
           if (x % 10 != 4 && x % 10 != 7) return false;
           x /= 10;
     }
     return true;
}

int main()
{
    Gen(0, 0); sort(V.begin(), V.end());
    scanf("%d %d", &n, &k);
    en = min(13, n);
    if (Fac(en) < ll(k)) printf("-1\n");
    else {
         getPerm(en);
         for (int i = 0; i < V.size() && V[i] <= n - en; i++) res++;
         for (int i = 0; i < en; i++)
             if (Lucky(n - en + 1 + i) && Lucky(n - en + 1 + perm[i])) res++;
         printf("%d\n", res);
    }
    return 0;
}