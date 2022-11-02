#include <iostream>
using namespace std;

int main() {
    int u[5][5];
    for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                    u[i][j] = 0;
    
    int m;
    
    cin >> m;
    for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            u[a][b] = u[b][a] = 1;
    }
    
    for(int i = 0; i < 5; ++i)
            for(int j = i + 1; j < 5; ++j)
                    for(int k = j + 1; k < 5; ++k)
                            if((u[i][j] && u[j][k] && u[i][k]) || (!u[i][j] && !u[i][k] && !u[j][k])) {
                                       cout << "WIN";
                                       return 0;
                            }
    cout << "FAIL";
    return 0;
}