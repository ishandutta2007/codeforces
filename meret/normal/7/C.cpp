#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long LL;

int gcd(int a, int b) {
    while (a && b) a > b ? a %= b : b %= a;
    return a + b;
}

pair<int, int> extended_gcd(int a, int b) {
    if (a % b == 0) {
        return make_pair(0, 1);
    } else {
        pair<int, int> p = extended_gcd(b, a % b);
        return make_pair(p.second, p.first - p.second * (a / b));
    }
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (c == 0) {
        printf("0 0\n");
        return 0;
    }
    int g = gcd(abs(a), abs(b));
    g = gcd(g, abs(c));
    a /= g;
    b /= g;
    c /= g;
    g = gcd(abs(a), abs(b));
    if (g > 1) {
        printf("-1\n");
        return 0;
    }
    if (a == 0) {
        printf("0 %d\n", - b * c);
        return 0;
    } else if (b == 0) {
        printf("%d 0\n", - a * c);
        return 0;
    }
    pair<int, int> p = extended_gcd(abs(a), abs(b));
    if (a < 0) p.first = -p.first;
    if (b < 0) p.second = -p.second;
    int x = p.first;
    int y = p.second;
    printf ("%lld %lld\n", x * LL(-c), y * LL(-c));
}