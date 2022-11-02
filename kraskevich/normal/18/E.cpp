#include <iostream>
using namespace std;

int Cfirst[500][26][26], Csecond[500][26][26];

void print(int i, int c1, int c2, int m) {
     if(i)
          print(i - 1, Cfirst[i][c1][c2], Csecond[i][c1][c2], m);
     for(int i = 0; i < m; ++i) 
             if(i % 2 == 0)
                  cout << char(c1 + 'a');
             else
                 cout << char(c2 + 'a');
     cout << endl;
}

int main() {
    int n, m;
    
    cin >> n >> m;
    
    char table[n][m];
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                    cin >> table[i][j];
    
    int f[n][26][26];
    
    for(int i = 0; i < n; ++i) 
         for(int j = 0; j < 26; ++j)
                 for(int k = 0; k < 26; ++k) {
                         if(k == j)
                              continue;
                         if(i) {
                             f[i][j][k] = 1000 * 1000 * 1000;
                             for(int c1 = 0; c1 < 26; ++c1)
                                     for(int c2 = 0; c2 < 26; ++c2) {
                                             if(c1 == c2 || c1 == j || c2 == k)
                                                   continue;
                                            if(f[i - 1][c1][c2] < f[i][j][k]) {
                                                   f[i][j][k] = f[i - 1][c1][c2];
                                                   Cfirst[i][j][k] = c1;
                                                   Csecond[i][j][k] = c2; 
                                            }
                                     }
                         }
                         else
                             f[i][j][k] = 0;
                         int cur = 0;
                         for(int l = 0; l < m; l += 2) 
                                 if(table[i][l] != j + 'a')
                                             ++cur;
                         for(int l = 1; l < m; l += 2)
                                 if(table[i][l] != k + 'a')
                                                ++cur;
                         f[i][j][k] += cur;
                 }
    int res = 1000 * 1000 * 1000, cl1, cl2;
    for(int i = 0; i < 26; ++i)
            for(int j = 0; j < 26; ++j)
                    if(i != j) 
                         if(res > f[n - 1][i][j]) {
                                cl1 = i;
                                cl2 = j;
                                res = f[n - 1][i][j];
                         }
    
    cout << res << endl;
    
    print(n - 1, cl1, cl2, m);
    cin >> n;
    
    return 0;
}