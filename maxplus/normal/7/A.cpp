#include <cstdio>
#include <vector>

using namespace std;

const int n = 8;
int ans = 64;

typedef vector<vector<char>> table;
typedef vector<bool> restr;
table a;

void paint(table &a, int x, restr ver)
{
    table na = a;
    bool b = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) if (a[i][j] == 'B')
    {
        b = 1;
        bool imp = 0;
        for (int I = 0; I < n; ++I)
            if (a[I][j] == 'W')
                imp = 1;
        if (!imp && !ver[j])
        {
            for (int I = 0; I < n; ++I)
                na[I][j] = 'G';
            paint(na, x + 1, ver);
            na = a;
        }
        imp = 0;
        for (int J = 0; J < n; ++J)
            if (a[i][J] == 'W')
                imp = 1;
        if (!imp)
        {
            for (int J = 0; J < n; ++J)
                na[i][J] = 'G';
            bool t = ver[j];
            ver[j] = 1;
            paint(na, x + 1, ver);
            ver[j] = t;
            na = a;
        }
        return;
    }
    ans = min(ans, x);
}

int main()
{
    a.resize(n);
    for (int i = 0; i < n && (a[i].resize(n), 1); ++i, getchar())
    for (int j = 0; j < n; ++j)
        a[i][j] = getchar();
//        a[i][j] = 'B';
    paint(a, 0, *(new restr(n, 0)));
    printf("%d", ans);
    return 0;
}