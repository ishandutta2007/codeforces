#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1000006;

bool prime[Maxn];
vector <int> pr;
int seq[3];
bool ok;

bool Prime(int x)
{
    if (x < Maxn) return prime[x];
    for (int i = 0; pr[i] * pr[i] <= x; i++)
        if (x % pr[i] == 0) return false;
    return true;
}

void Traverse(int lvl, int n)
{
    if (n == 0) {
        printf("%d\n", lvl);
        for (int i = 0; i < lvl; i++)
            printf("%d%c", seq[i], i + 1 < lvl? ' ': '\n');
        ok = true;
    } else if (lvl >= 3) return;
    else {
        for (int i = n; i >= 2 && !ok; i--)
            if (Prime(i)) {
                seq[lvl] = i; Traverse(lvl + 1, n - i);
            }
    }
}

int main()
{
    fill(prime + 2, prime + Maxn, true);
    for (int i = 2; i < Maxn; i++) if (prime[i]) {
        pr.push_back(i);
        for (int j = i + i; j < Maxn; j += i)
            prime[j] = false;
    }
    int n; scanf("%d", &n);
    Traverse(0, n);
    return 0;
}