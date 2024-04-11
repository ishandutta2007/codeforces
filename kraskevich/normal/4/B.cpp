#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, sum;
    
    cin >> n >> sum;
    
    int mn[n], mx[n];
    
    for(int i = 0; i < n; ++i)
            cin >> mn[i] >> mx[i];
    
    bool f[n][sum + 1];
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j <= sum; ++j)
                    f[i][j] = false;
    
    for(int i = mn[0]; i <= mx[0]; ++i)
            f[0][i] = true;
    
    for(int i = 1; i < n; ++i)
            for(int j = mn[i]; j <= sum; ++j)
                    for(int k = max(0, j - mx[i]); k <= j - mn[i]; ++k)
                            if(f[i - 1][k])
                                   f[i][j] = true;
    if(!f[n - 1][sum]) {
            cout << "NO";
            return 0;
    }
    
    cout << "YES" << endl;
    
    vector<int> ans;
    int cur = sum;
    int i = n - 1;
    while(i > 0) {
           int j = max(0, cur - mx[i]);
           while(!f[i - 1][j])
                      ++j;
           ans.push_back(cur - j);
           --i;
           cur = j;
    }
    
    ans.push_back(cur);
    
    for(int i = n - 1; i >= 0; --i)
            cout << ans[i] << " ";
    
    cin >> n;
    
    return 0;
}