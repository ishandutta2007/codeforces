#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, v;
    
    cin >> n >> m >> v;
    
    --v;
    int b = 0;
    if(!v)
          ++b;
         
    if(m > (n - 1) * (n - 2) / 2 + 1 || m < n - 1)
         cout << -1;
    else {
         int sum = n - 1;
         for(int i = 0; i < n; ++i)
                 if(i != v)
                      cout << i + 1 << " " << v + 1 << endl;
         for(int i = 0; i < n && sum < m; ++i)
                 for(int j = i + 1; j < n && sum < m; ++j)
                         if((j != b &&  i != b) && i != v && j != v) {
                               cout << i + 1 << " " << j + 1 << endl;
                               ++sum;
                         }
    }
         
    
    cin >> n;
    
    return 0;
}