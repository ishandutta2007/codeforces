#include <iostream>
#include <string>
using namespace std;

int res;

char c[10][10];
int n, m;
bool b[10][10];

int main() {
   cin >> n >> m;
   for(int i = 0; i < n; ++i)
           for(int j = 0; j < m; ++j) {
                   b[i][j] = false;
                   cin >> c[i][j];
           }
   int res = 0;
   for(int i = 0; i < n; ++i)
                 for(int j = 0; j < m; ++j) {
                         if(c[i][j] != 'W')
                                    continue;
                         int t = 0;
                         if(i > 0 && c[i - 1][j] == 'P')
                              ++t;   
                         if(j > 0 && c[i][j - 1] == 'P')
                              ++t;
                         if(i < n - 1 && c[i + 1][j] == 'P')
                              ++t;
                         if(j < m - 1 && c[i][j + 1] == 'P')
                              ++t;          
                         res += t ? 1 : 0;
                 }
   
   cout << res << endl;
   
   cin >> n;
   return 0;
}