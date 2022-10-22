#include <iostream>
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

    vec< string > a(8);

    for(int i = 0;i < 8;i++) cin >> a[i];

    int mn1 = inf, mn2 = inf;

    for(int i = 0;i < 8;i++) {
        for(int j = 0;j < 8;j++) {
            if(a[i][j] == '.') continue;

            if(a[i][j] == 'W') {
                
                int ok = 1;

                for(int q = i - 1;q >= 0;q--) {
                    if(a[q][j] != '.') ok = 0;
                }

                if(ok) {
                    mn1 = min(mn1, i);
                }

            }else {
            
                int ok = 1;

                for(int q = i + 1;q < 8;q++) {
                    if(a[q][j] != '.') ok = 0;
                }

                if(ok) {
                    mn2 = min(mn2, 8 - i - 1);
                }
            }
        }
    }

    puts(mn1 <= mn2? "A" : "B");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}