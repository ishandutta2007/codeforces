#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int cnt[256];

int main() {
    
    int n;
    cin >> n;
    if (n == 1) {
        printf("Yes\n");
        return 0;
    }
    string s;
    cin >> s;
    
    for (char c : s) {
        if (cnt[c] > 0) {
            printf("Yes\n");
            return 0;
        }
        cnt[c]++;
    }
    
    printf("No\n");
    
    return 0;
}