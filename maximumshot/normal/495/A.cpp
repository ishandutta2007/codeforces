#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    int n;
    string s;

    cin >> s;

    if(s[0] == '0') n = s[1] - '0';
    else n = (s[0] - '0') * 10 + s[1] - '0';

    vec<int> mat(10);

    mat[0] = 2;
    mat[1] = 7;
    mat[2] = 2;
    mat[3] = 3;
    mat[4] = 3;
    mat[5] = 4;
    mat[6] = 2;
    mat[7] = 5;
    mat[8] = 1;
    mat[9] = 2;

    cout << mat[n / 10] * mat[n % 10] << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}