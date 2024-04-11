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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    string s;
    cin >> s;

    int ans = 0;

    for(int i = 0;i < n;i++) {
        if(s[i] != '.') continue;
        int j = i;
        while(j < n && s[j] == '.') j++; j--;
        ans += j - i;
        i = j;
    }

    while(m--) {
        int pos;
        char c;
        scanf("%d %c", &pos, &c);
        pos--;

        if(c == '.' && s[pos] != '.') {
            if(pos == 0) {
                if(n > 1 && s[pos + 1] == '.') ans++;
            }else if(pos == n - 1) {
                if(n > 1 && s[pos - 1] == '.') ans++;
            }else {
                if(s[pos - 1] == '.' && s[pos + 1] == '.') ans += 2;
                else if(s[pos - 1] == '.' || s[pos + 1] == '.') ans++;
            }
        }

        if(c != '.' && s[pos] == '.') {
            if(pos == 0) {
                if(n > 1 && s[pos + 1] == '.') ans--;
            }else if(pos == n - 1) {
                if(n > 1 && s[pos - 1] == '.') ans--;
            }else {
                if(s[pos - 1] == '.' && s[pos + 1] == '.') ans -= 2;
                else if(s[pos - 1] == '.' || s[pos + 1] == '.') ans--;
            }
        }

        printf("%d\n", ans);
        s[pos] = c;
    }

    return true;
}

int main() {

    //while(solve());
    solve();    

    return 0;
}