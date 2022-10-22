#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, k;
int seq[Maxn], slen;

int main()
{
    scanf("%d %d", &n, &k);
    int l = 1, r = k + 1;
    bool lft = true;
    while (l <= r) {
        if (lft) { seq[slen++] = l; l++; }
        else { seq[slen++] = r; r--; }
        lft = !lft;
    }
    for (int i = k + 2; i <= n; i++)
        seq[slen++] = i;
    for (int i = 0; i < n; i++)
        printf("%d%c", seq[i], i + 1 < n? ' ': '\n');
    return 0;
}