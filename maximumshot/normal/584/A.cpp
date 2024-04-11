#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double LD;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve()
{
    int n, t;

    cin >> n >> t;

    if(t < 10) {
        for(int i = 0;i < n;i++) cout << t;
        cout << '\n';
    }else {
        if(n == 1) {cout << -1 << '\n'; return true;}
        cout << 1;
        for(int i = 0;i < n - 1;i++) cout << 0;
        cout << '\n';
    }

    return true;
} 

int main() {

    //while(solve());
    solve();

    return 0;
}