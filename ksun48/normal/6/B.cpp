#include <iostream>
using namespace std;

int main() {
    int n, m;
    char c[2];
    cin >> n >> m >> c;
    char stuff[n+1][m+1];
    for(int i = 0; i < n; i++){
        cin >> stuff[i];
    }
    int colors[26];
    for(int i = 0; i < 26; i++) colors[i] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(stuff[i][j] >= 'A' && stuff[i][j] <= 'Z' && stuff[i][j] != c[0]){
                if(i+1 < n && stuff[i+1][j] == c[0]){
                    colors[stuff[i][j] - 'A'] = 1;
                }
                                if(i-1 >=0 && stuff[i-1][j] == c[0]){
                    colors[stuff[i][j] - 'A'] = 1;
                }
                                if(j+1 < m && stuff[i][j+1] == c[0]){
                    colors[stuff[i][j] - 'A'] = 1;
                }
                if(j-1 >=0 && stuff[i][j-1] == c[0]){
                    colors[stuff[i][j] - 'A'] = 1;
                }
            }
        }
    }
    int k = 0;
    for(int i = 0; i < 26; i++){
        k += colors[i];
    }
    cout << k << endl;
    return 0;
}