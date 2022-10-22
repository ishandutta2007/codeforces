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
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int x;

    scanf("%d", &x);

    string a[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    string b[10] = {"0", "0", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if(x < 20) {
        cout << a[x] << '\n';
    }else {
        cout << b[x / 10] << (x % 10?"-" + a[x % 10] + "\n" : "\n");
    }
    

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}