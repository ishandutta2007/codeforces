#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


struct Action
{
    int x1, y1, x2, y2;

    Action(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

    void print()
    {
        printf("%d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
    }
};

const int LEN = (int) 1e5 + 100;
const int N = 305;
char str[LEN];

struct Field
{
    int n, m;
    string f[N][N];

    void readF(int _n, int _m)
    {
        n = _n;
        m = _m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%s", str);
                f[i][j] = string(str);
            }
    }

    void reverseAll()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                reverse(f[i][j].begin(), f[i][j].end());
    }

    void apply(Action x)
    {
        char c = f[x.x1][x.y1].back();
        f[x.x1][x.y1].pop_back();
        f[x.x2][x.y2].insert(f[x.x2][x.y2].begin(), c);
    }

    vector <Action> getToAngle()
    {
        vector <Action> ans, add;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int len = f[i][j].length();
                for (int h = len - 1; h >= 0; h--)
                {
                    int ni = 0;
                    if (f[i][j][h] == '1')
                        ni = n - 1;
                    int nj = j;
                    if (i == ni)
                    {
                        nj = j - 1;
                        if (nj < 0)
                            nj = j + 1;
                    }
                    ans.emplace_back(i, j, ni, nj);
                    if (nj != 0)
                        add.emplace_back(ni, nj, ni, 0);
                    }
            }
        for (auto x : add)
            ans.push_back(x);
        return ans;
    }

    void eprint()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                eprintf("%s ", f[i][j].c_str());
            eprintf("\n");
        }
    }

} A, B, C;



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    A.readF(n, m);
    B.readF(n, m);
    B.reverseAll();
    vector <Action> a = A.getToAngle(), b = B.getToAngle();
    reverse(b.begin(), b.end());
    vector <Action> ans;
    for (auto x : a)
        ans.push_back(x);
    for (auto x : b)
        ans.emplace_back(x.x2, x.y2, x.x1, x.y1);
    printf("%d\n", (int) ans.size());
    for (auto x : ans)
        x.print();

//    C = A;
//    for (auto x : ans)
//        C.apply(x);
//    C.eprint();

	return 0;
}