#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
bool isLeaf[N];
vector<int> edge[N];

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        isLeaf[i] = true;
    }
    
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        isLeaf[x] = false;
        edge[x].push_back(i);
    }
    
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        if (!isLeaf[i]) {
            int cnt = 0;
            for (int u : edge[i]) {
                if (isLeaf[u]) {
                    cnt++;
                }
            }
            ans &= (cnt >= 3);
        }
    }
    
    printf(ans ? "Yes\n" : "No\n");
    
    return 0;
}