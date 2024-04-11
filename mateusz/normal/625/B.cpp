#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, m;
char word[N];
char pattern[N];

bool ends(int i) {
    
    for (int j = 1; j <= m; j++) {
        if (pattern[m - j + 1] != word[i - j + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    
    scanf("%s %s", &word[1], &pattern[1]);
    n = strlen(word + 1);
    m = strlen(pattern + 1);
    
    int last = 0;
    int ans = 0;
    for (int i = m; i <= n; i++) {
        if (ends(i) && i - last >= m) {
            last = i;
            ans++;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}