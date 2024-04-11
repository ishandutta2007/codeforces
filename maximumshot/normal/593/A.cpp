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
#include <time.h>

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

    vec< string > a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    int ans = 0;

    for(char k1 = 'a';k1 <= 'z';k1++) {
        for(char k2 = 'a';k2 <= 'z';k2++) {
            
            int tmp = 0;

            for(int i = 0;i < n;i++) {
                
                int ok = 1;
                for(int j = 0;j < (int)a[i].size();j++) {
                    if(a[i][j] != k1 && a[i][j] != k2) {
                        ok = 0;
                        break;
                    }
                }

                if(ok) tmp += (int)a[i].size();
            }

            ans = max(ans, tmp);
        }
    }

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}