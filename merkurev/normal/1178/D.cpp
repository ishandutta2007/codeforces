#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif


const int N = 5005;
bool isP[N];
vector <pair <int, int>> comps[N];
vector <pair <int, int>> base = {make_pair(3, 3), make_pair(4, 4), make_pair(4, 6), make_pair(4, 5), make_pair(5, 5), make_pair(6, 7)};

void init()
{
    memset(isP, true, sizeof isP);
    isP[0] = isP[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (!isP[i]) continue;
        for (int j = i * i; j < N; j += i)
            isP[j] = false;
    }
    for (int i = 3; i <= 1000; i++)
    {
        int e = i;
        while (!isP[e])
            e++;
        int v = i;
        if (v == 5)
        {
            comps[i].emplace_back(5, 5);
            v -= 5;
            e -= 5;
        }
        if (v == 6)
        {
            comps[i].emplace_back(6, 7);
            v -= 6;
            e -= 7;
        }
        if (v == 9)
        {
            comps[i].emplace_back(4, 6);
            comps[i].emplace_back(5, 5);
            v -= 4;
            e -= 6;
            v -= 5;
            e -= 5;
        }
        while (e >= v + 2)
        {
            comps[i].emplace_back(4, 6);
            e -= 6;
            v -= 4;
        }
        while (e >= v + 1)
        {
            comps[i].emplace_back(4, 5);
            e -= 5;
            v -= 4;
        }
        while (v % 3 != 0)
        {
            comps[i].emplace_back(4, 4);
            e -= 4;
            v -= 4;
        }
        while (v > 0)
        {
            comps[i].emplace_back(3, 3);
            e -= 3;
            v -= 3;
        }
        if (v < 0 || e < 0 || e > 0 || v > 0)
        {
            eprintf("bad for %d\n", i);
        }
    }

}

void printAns(int n)
{
    vector <pair <int, int>> ans;
    int fst = 0;
    for (auto p : comps[n])
    {
        int v = p.first, e = p.second;
        for (int i = 0; i < v; i++)
            ans.emplace_back(fst + i, fst + (i + 1) % v);
        if (e - v == 2)
        {
            ans.emplace_back(fst, fst + 2);
            ans.emplace_back(fst + 1, fst + 3);
        }
        else if (e - v == 1)
        {
            ans.emplace_back(fst, fst + 2);
        }
        else if (e - v != 0) throw;
        fst += v;
    }
    printf("%d\n", (int) ans.size());
    for (auto p : ans)
        printf("%d %d\n", p.first + 1, p.second + 1);
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    init();

    int n;
    scanf("%d", &n);
    if (n == 2)
    {
        printf("-1\n");
        return 0;
    }

    printAns(n);

    return 0;
}