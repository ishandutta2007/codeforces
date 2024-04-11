
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef double D;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FOREACH(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)(a).size())
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

int gcd(int a, int b) {
    while (a && b) {
        a > b ? a %= b : b %= a;
    }
    return a + b;
}

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    int cur = 0;

    while (true) {
        int g = gcd(a, n);
        if (n < g) {
            break;
        }
        n -= g;
        swap(a, b);
        cur = !cur;
    }
    printf("%d\n", !cur);

    return 0;
}