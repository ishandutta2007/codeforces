#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;


multiset<int> res, a, b;
int n, m;

int getB(int A)
{
    int want = m - 1 - A;
    auto it = b.upper_bound(want);
    if (it == b.begin())
        it = b.end();
    --it;
    return *it;
}

int getA(int B)
{
    int want = m - 1 - B;
    auto it = a.upper_bound(want);
    if (it == a.begin())
        it = a.end();
    --it;
    return *it;
}

void solveA(int);
void solveB(int);

void solveA(int A)
{
    while (a.find(A) != a.end())
    {
        int goB = getB(A);
        int goA = getA(goB);
        int f1 = (A + goB) % m;
        int f2 = (goB + goA) % m;
        if (f2 > f1)
        {
            solveB(goB);
        }
        else
        {
            a.erase(a.find(A));
            b.erase(b.find(goB));
            res.insert(-f1);
        }
    }
}

void solveB(int B)
{
    while (b.find(B) != b.end())
    {
        int goA = getA(B);
        int goB = getB(goA);
        int f1 = (B + goA) % m;
        int f2 = (goA + goB) % m;
        if (f2 > f1)
        {
            solveA(goA);
        }
        else
        {
            a.erase(a.find(goA));
            b.erase(b.find(B));
            res.insert(-f1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
    }

    for (int i = 0; i < m; i++)
        solveA(i);
    for (int i = 0; i < m; i++)
        solveB(i);

    for (int x: res)
        cout << -x << " ";

    return 0;
}