#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f[1000 * 1000 + 1];
int p[1000 * 1000 + 1];

int main() {
   int n;
   
   cin >> n;
   
   for(int i = 0; i <= 1000 * 1000; ++i) {
           p[i] = -1;
           f[i] = 1000 * 1000 * 1000;
   }
   f[4] = f[7] = 1;
   p[4] = 4;
   p[7] = 7;
   for(int i = 8; i <= n; ++i) {
           if(f[i - 4] <= f[i - 7]) {
                  f[i] = f[i - 4] + 1;
                  p[i] = i - 4;
           }
           else {
                f[i] = f[i - 7] + 1;
                p[i] = i - 7;
           }
   }
   vector<int> ans;
   if(f[n] >= 1000 * 1000 * 1000) {
           cout << -1;
           cin >> n;
   }
   else {
        int i = n;
        for(i = n; p[i] != i; i = p[i])
              ans.push_back(p[i] == i - 7 ? 7 : 4);
        ans.push_back(i);
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i)
                cout << ans[i];
        cin >> n;
   }
   return 0;                 
}