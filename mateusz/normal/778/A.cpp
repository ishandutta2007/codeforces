#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m;
char t[N], p[N];
bool removed[N];
int per[N];

bool good(int w) {
    for (int i = 1; i <= w; i++) {
        removed[per[i]] = true;
    }
    
    bool ret = true;
    int ptr = 1;
    for (int i = 1; i <= m; i++) {
        while (ptr <= n && (t[ptr] != p[i] || removed[ptr])) {
            ptr++;
        }
        if (ptr > n) {
            ret = false;
            break;
        }
        ptr++;
    }
    
    for (int i = 1; i <= w; i++) {
        removed[per[i]] = false;
    }
    
    return ret;
}

int main() {
    
    scanf("%s %s", &t[1], &p[1]);
    n = strlen(t + 1);
    m = strlen(p + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &per[i]);
    }
    
    int low = 1;
    int high = n;
    int res = 0;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid)) {
            low = mid + 1;
            res = mid;
        } else {
            high = mid - 1;
        }
    }
    
    printf("%d\n", res);
    return 0;
}