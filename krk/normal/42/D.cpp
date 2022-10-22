#include <cstdio>
using namespace std;

const int Maxn = 22;

int n;
int col[Maxn];

int main()
{
    scanf("%d", &n);
    int cur = 0;
    for (int a = 0; cur < n; a++) {
        bool good = true;
        for (int i = 0; i < cur && good; i++)
            for (int j = i + 1; j < cur && good; j++)
                for (int l = 0; l < cur && good; l++)
                    if (i != l && j != l) good = a != col[i] + col[j] - col[l];
        if (good) col[cur++] = a;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) printf("%d%c", i == j? 0: col[i] + col[j], j + 1 < n? ' ': '\n');
    return 0;
}