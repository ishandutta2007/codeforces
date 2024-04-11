#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt(vector<pair<int, int> > a, int x) {
    int l = 0, r = a.size() - 1;
    while(l < r) {
            int m = (l + r) / 2;
            if(a[m].first < x)
                          l = m + 1;
            else
                r = m;
    }
    return (a[l].first == x ? a[l].second : 0);
} 
                

int main() {
   int n;
   
   cin >> n;
   
   int a[n];
   
   for(int i = 0; i < n; ++i) 
           cin >> a[i];
   
   sort(a, a + n);
   vector<pair<int, int> > res;
   int k = 1;
   for(int i = 0; i < n; ++i) {
             if(i != n - 1 && a[i] == a[i + 1])
                     ++k;
             else {
                  res.push_back(pair<int, int>(a[i], k));
                  k = 1;
             }
   }
    
   long long ans = 0;                         
   for(int i = 0; i < n; ++i) {
           int cur = cnt(res, -a[i]);
           if(!a[i])
                    --cur;
           ans += (long long)cur;
   }
   
   cout << ans / 2;
   
   cin >> n;
   
   return 0;     
}