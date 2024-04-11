#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char stuff[n+1][m+1];
    for(int i = 0; i < n; i++){
        cin >> stuff[i];
    }
    int c[m];
    int r[n];
    for(int i = 0; i < n; i++) r[i] = 1;
    for(int i = 0; i < m; i++) c[i] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(stuff[i][j] == 'S'){
                r[i] = 0;
                c[j] = 0;
            }
        }
    }

    int c1 = 0, r1 = 0;
    for(int i = 0; i < n; i++) r1 += 1-r[i];
    for(int i = 0; i < m; i++) c1 += 1-c[i];
    cout << m*n-r1*c1 << endl;
    return 0;
}