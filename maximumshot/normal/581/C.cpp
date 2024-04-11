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
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool solve() {
        
    int n, k;

    scanf("%d %d", &n, &k);

    vec< pair< int, int > > a(n + 1);

    for(int i = 1;i <= n;i++) {
        int x;
        scanf("%d", &x);
        a[i] = mp(x % 10, x);
    }

    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());

    //for(int i = 1;i <= n;i++) cout << a[i].first << " ";
    //cout << '\n';

    for(int i = 1;i <= n && k > 0;i++) {
        if(a[i].first == 0) break;
        int mod = a[i].first;
        int value = a[i].second;
        if(10 - mod <= k) {
            k -= (10 - mod);
            value += (10 - mod);
            mod = 0;
        }
        a[i] = mp(mod, value);
        //cout << value << " ";
    }

    int ans = 0;

    for(int i = 1;i <= n;i++) {
        int value = a[i].second;
        int can = (100 - value);
        if(can <= k) {
            value = 100;
            k -= can;
        }else {
            value += k;
            k = 0;
        }
        ans += value / 10;
    }

    printf("%d\n", ans);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}