#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int stuff[n][101];
    for(int i = 0; i< n; i++) for(int j = 0; j <= 100; j++) stuff[i][j] = 0;
    for(int i = 0; i < n; i++){
        int r;
        cin >> r;
        for(int q = 0; q < r; q++){
            int t;
            cin >> t;
            stuff[i][t]++;
        }
    }
    for(int i = 0; i < n; i++){
        int no = 1;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int yes = 0;
            for(int k = 0; k <= 100; k++){
                if(stuff[j][k]>stuff[i][k]) yes = 1;
            }
            if(yes == 0){
                no = 0;
            }
        }
        if(no){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}