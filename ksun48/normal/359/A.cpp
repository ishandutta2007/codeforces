#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for(int i = 0; i < m; i++){
        for(int j= 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) continue;
            if(i == 0 || i == m-1 || j == 0 || j == n-1){
                cout << 2 << endl;
                return 0;
            }
        }
    }
    cout << 4 << endl;
    return 0;
}