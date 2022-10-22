#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = 1000000007;

using namespace std;

bool solve()
{
    string a;

    cin >> a;

    int pos = (a[0] == 'f'?3 : 4);

    for(int i(0);i < pos;i++) cout << a[i];
    cout << "://";

    int ind;

    for(int i((int)a.size() - 1);i > pos;i--)
    {
        if(a[i] == 'u' && a[i - 1] == 'r')
        {
            ind = i - 1;
            break;
        }
    }

    for(int i(pos);i < ind;i++) cout << a[i];
    cout << ".ru";

    if(ind + 2 < (int)a.size()) cout << '/';
    for(int i(ind + 2);i < (int)a.size();i++) cout << a[i];

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}