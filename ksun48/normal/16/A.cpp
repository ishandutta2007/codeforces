#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char stuff[n+1][m+1];
    for(int i = 0; i < n; i++){
        cin >> stuff[i];
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            if(stuff[i][j] == stuff[i+1][j]){
                cout << "NO\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            if(stuff[i][j] != stuff[i][j+1]){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}