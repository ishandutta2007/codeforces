#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, M = 1e9 + 7;

int n;
char word[N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int main() {
    scanf("%s", &word[1]);
    n = strlen(word + 1);
    
    int ans = 0;
    int bOnRight = 0;
    for (int i = n; i >= 1; i--) {
        if (word[i] == 'a') {
            add(ans, bOnRight);
            add(bOnRight, bOnRight);
        } else {
            add(bOnRight, 1);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}