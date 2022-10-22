#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

const LL N = 100100;

bool solve()
{
    int n;

    cin >> n;

    string a;

    cin >> a;

    int sum = 0, sum2 = 0;

    for(int i(0);i < n / 2;i++)
    {
        if(a[i] != '4' && a[i] != '7') {cout << "NO\n"; return true;}
        if(a[n - i - 1] != '4' && a[n - i - 1] != '7') {cout << "NO\n"; return true;}
        sum += a[i] - '0';
        sum2 += a[n - i - 1] - '0';
    }

    cout << (sum == sum2?"YES\n" : "NO\n");

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}