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
    int n, k;

    cin >> n >> k;

    LL u, d;

    u = n;
    d = 1;


    for(int i(0);i < k;i++)
    {
        if(i % 2 == 0) cout << d++ << ' ';
        else cout << u-- << ' ';
    }

    if(k % 2) for(int i(k);i < n;i++) cout << d++ << ' ';
    else for(int i(k);i < n;i++) cout << u-- << ' ';
    
    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}