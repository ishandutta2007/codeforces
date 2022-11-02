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

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

int n;
string s, t;
int have[2][2];
int cnt1 = 0;
int cnt2 = 0;

void work1()
{
    if (have[1][1])
    {
        ++cnt1;
        --have[1][1];
        return;
    }
    if (have[1][0])
    {
        ++cnt1;
        --have[1][0];
        return;
    }
    if (have[0][1])
    {
        --have[0][1];
        return;
    }
    if (have[0][0])
    {
        --have[0][0];
        return;
    }
}

void work2()
{
    if (have[1][1])
    {
        ++cnt2;
        --have[1][1];
        return;
    }
    if (have[0][1])
    {
        ++cnt2;
        --have[0][1];
        return;
    }
    if (have[1][0])
    {
        --have[1][0];
        return;
    }
    if (have[0][0])
    {
        --have[0][0];
        return;
    }
}

void solve()
{
    cin >> n;
    cin >> s >> t;

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            have[i][j] = 0;

    for (int i = 0; i < 2 * n; ++i)
        ++have[s[i] - '0'][t[i] - '0'];

    for (int i = 0; i < n; ++i)
    {
        work1();
        work2();
    }

    if (cnt1 > cnt2)
        cout << "First";
    if (cnt1 == cnt2)
        cout << "Draw";
    if (cnt1 < cnt2)
        cout << "Second";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}