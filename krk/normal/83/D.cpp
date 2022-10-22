#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 44730;
const int Inf = 2000000005;

int a, b, k;
int lst[Maxn];
int pr[Maxn], len;
int res;

void Eratosten()
{
     fill(lst, lst + Maxn, Inf);
     for (int i = 2; i < Maxn; i++) if (lst[i] == Inf) {
         pr[len++] = i; lst[i] = i;
         for (int j = i * i; j < Maxn; j += i) if (i < lst[j]) lst[j] = i;
     }
}

bool Prime(int x)
{
     if (x == 2) return true;
     if (x % 2 == 0) return false;
     for (int i = 3; i * i <= x; i += 2)
         if (x % i == 0) return false;
     return true;
}

int f(int k, int n)
{
    int res = 0, nxt = n / k;
    if (k >= nxt) for (int i = 1; i <= nxt; i++) { if (lst[i] >= k) res++; }
    else {
         res = nxt;
         for (int i = 0; i < len && pr[i] < k; i++) res -= f(pr[i], nxt);
    }
    return res;
}

int main()
{
    scanf("%d %d %d", &a, &b, &k);
    if (!Prime(k)) printf("0\n");
    else {
         Eratosten();
         printf("%d\n", f(k, b) - f(k, a - 1));
    }
    return 0;
}