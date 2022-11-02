#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <ctime>
#include <ctype.h>

using namespace std;

void open_files()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct vertex
{
    int v, weight;
    vertex(int _v = 0, int _weight = 0): v(_v), weight(_weight) {}
};

bool cmp (vertex a, vertex b)
{
    return a.weight < b.weight;
}

const int N = 100 * 1000 + 100;
vector<vertex> white;
vector<vertex> black;
vector<int> p(N);
vector<int> c(N);

int get(int v)
{
    return v == p[v] ? v : p[v] = get(p[v]);
}

void unite(int a, int b)
{
    a = get(a);
    b = get(b);
    p[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //open_files();

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int weight, col;
        cin >> col >> weight;
        if (col == 0)
            white.push_back(vertex(i, weight));
        else
            black.push_back(vertex(i, weight));
        p[i] = i;
        c[i] = col;
    }

    sort(white.begin(), white.end(), cmp);
    sort(black.begin(), black.end(), cmp);

    int ptrw = 0, ptrb = 0;
    for (;;)
    {
        cout << white[ptrw].v + 1 << " " << black[ptrb].v + 1 << " " << min(white[ptrw].weight, black[ptrb].weight) << "\n";
        int add = min(white[ptrw].weight, black[ptrb].weight);
        white[ptrw].weight -= add;
        black[ptrb].weight -= add;
        unite(white[ptrw].v, black[ptrb].v);
        if (white[ptrw].weight == 0)
            ++ptrw;
        if (black[ptrb].weight == 0)
            ++ptrb;
        if (ptrw == white.size() || ptrb == black.size())
            break;
    }

    for (int i = 0; i < n; ++i)
    {
        if (c[i] == 0)
        {
            if (get(i) != get(black[0].v))
            {
                unite(i, black[0].v);
                cout << i + 1 << " " << black[0].v + 1 << " " << 0 << "\n";
            }
        }
        else
        {
            if (get(i) !=  get(white[0].v))
            {
                unite(i, white[0].v);
                cout << i + 1 << " " << white[0].v + 1 << " " << 0 << "\n";
            }
        }
    }
}