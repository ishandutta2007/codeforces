#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

bool solve()
{
    vec< vec<char> > mat, ans;
    int w, h;

    cin >> w >> h;

    mat.resize(h, vec<char>(w));
    ans.resize(w, vec<char>(h));

    for(int i(0);i < h;i++) 
    {
        mat[i].resize(w);
        for(int j(0);j < w;j++)
        {
            cin >> mat[i][j];
            ans[j][h - i - 1] = mat[i][j];
        }
    }

    mat.resize(w, vec<char>(h));

    for(int i(0);i < w;i++)
    {
        mat[i].resize(h);
        for(int j(0);j < h;j++)
            mat[i][h - 1 - j] = ans[i][j];
    }

    ans.resize(2 * w);

    for(int i(0);i < w;i++)
    {
        ans[2 * i].resize(2 * h);
        ans[2 * i + 1].resize(2 * h);
        for(int j(0);j < h;j++)
            ans[2 * i][2 * j] = ans[2 * i][2 * j + 1] = ans[2 * i + 1][2 * j] = ans[2 * i + 1][2 * j + 1] = mat[i][j];
    }

    for(auto i : ans)
    {
        for(auto j : i) cout << j;
        cout << '\n';
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}