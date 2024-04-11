#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pow10(int n) {
    int res = 1;
    for(int i = 0; i < n; ++i)
            res *= 10;
    return res;
}

int main() {
    int n, k;
    
    cin >> n >> k;
    
    char a[n][k];
    int pos[k];
    
    for(int i = 0; i < k; ++i)
            pos[i] = i;
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < k; ++j)
                    cin >> a[i][j];
    
    int res = 1000 * 1000 * 1000;
    for(int i = 0; i < 8 * 7 * 6 * 5 * 4 * 3 * 2; ++i) {
            int mx = 0, mn = 1000 * 1000 * 1000;
            for(int j = 0; j < n; ++j) {
                    int cur = 0;
                    for(int l = 0; l < k; ++l) 
                            cur += pow10(pos[l]) * (int)a[j][l];
                    mn = min(mn, cur);
                    mx = max(mx, cur);
            }
            res = min(res, mx - mn);
            next_permutation(pos, pos + k);
    }
    
    cout << res;
    
    cin >> n;
    
    return 0;
}