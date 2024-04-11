#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

int n;
int p[Maxn], b[Maxn];
int inb[Maxn];
int res;
int best[Maxn];
vector <ii> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        inb[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        p[i] = inb[p[i]];
    for (int i = 1; i <= n; i++) {
        int pos = i;
        while (p[pos] != i) pos++;
        res += pos - i;
        best[i] = p[i];
        for (int j = i + 1; j < pos; j++)
            best[j] = max(best[j - 1], p[j]);
        for (int j = pos - 1; j >= i; j--)
            if (best[j] == p[j]) {
                seq.push_back(ii(j, pos));
                swap(p[j], p[pos]); pos = j;
            }
    }
    printf("%d\n", res);
    printf("%d\n", seq.size());
    for (int i = 0; i < seq.size(); i++)
        printf("%d %d\n", seq[i].first, seq[i].second);
    return 0;
}