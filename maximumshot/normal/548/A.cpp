#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

typedef long long LL;

bool solve() {

    string s;
    cin >> s;
    int k, n = (int)s.size();
    cin >> k;
    
    if(n % k) {
        puts("NO");
        return true;
    }

    int len = n / k;

    bool ok = 1;

    for(int i(0);i < n;i += len) {
        // [i .. i + len - 1]
        for(int q(i + len - 1), j(i);j <= i + len - 1;j++, q--) {
            ok &= (s[j] == s[q]);
        }
    }

    puts(ok?"YES" : "NO");

    return true;
}

int main() {
    //while(solve());
    solve();

    return 0;
}