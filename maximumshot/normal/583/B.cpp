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
    
    int n;
    cin >> n;
    vec< int > a(n + 1);

    for(int i = 1;i <= n;i++) cin >> a[i];


    int ans = 0, now = 0;

    vec< int > hacked(n + 1, 0);

    for(int i = 0;;i ^= 1, ans++) {
        int ok = 1;
        for(int j = 1;j <= n;j++) {
            if(!hacked[j]) {
                ok = 0;break;
            }
        }
        if(ok) break;
        if(i == 0) {
            for(int j = 1;j <= n;j++) {
                if(hacked[j]) continue;
                if(a[j] <= now) {
                    now++;
                    hacked[j] = 1;
                }
            }   
        }else {
            for(int j = n;j >= 1;j--) {
                if(hacked[j]) continue;
                if(a[j] <= now) {
                    now++;
                    hacked[j] = 1;
                }
            }
        }
    }

    cout << ans - 1 << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}