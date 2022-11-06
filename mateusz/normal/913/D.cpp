#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, T;
int tab[N], a[N], t[N];

bool cmp(int a, int b) {
    return t[a] < t[b];
}

int main() {
    
    scanf("%d %d", &n, &T);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &t[i]);
        tab[i] = i;
    }
    
    sort(tab + 1, tab + 1 + n, cmp);
    
    int low = 1;
    int high = n;
    int res = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int sumTime = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[tab[i]] >= mid) {
                cnt++;
                sumTime += t[tab[i]];
            }
            if (cnt == mid) {
                break;
            }
        }
        if (sumTime > T || cnt < mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
            res = mid;
        }
    }
    
    vector<int> ans;
    if (res > 0) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[tab[i]] >= res) {
                cnt++;
                ans.push_back(tab[i]);
            }
            if (cnt == res) {
                break;
            }
        }
    }
    
    printf("%d\n%d\n", ans.size(), ans.size());
    
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}