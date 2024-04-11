#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {

    string s;
    cin >> s;
    
    int cntA = 0, cntB = 0;
    for(auto c : s) {
        if (c == '-') cntA++;
        else cntB++;
    }
    
    if (cntB == 0) {
        printf("YES\n");
        return 0;
    }
    
    printf(cntA % cntB == 0 ? "YES\n" : "NO\n");
    
    return 0;
}