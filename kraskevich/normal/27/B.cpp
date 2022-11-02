#include <iostream>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int f[n][n];
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    f[i][j] = -1;
    
    int rank[n];
    
    for(int i = 0; i < n; ++i)
            rank[i] = 0;
    
    for(int i = 0; i < n * (n - 1) / 2 - 1; ++i) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            rank[x]++;
            f[x][y] = f[y][x] = 1;
    }
    
    for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j) 
                    if(f[i][j] == -1) {
                               if(rank[i] > rank[j])
                                          cout << i + 1 << " " << j + 1;
                               else
                                   cout << j + 1 << " " << i + 1;
                    }
     
    cin >> n;
    
    return 0;  
}