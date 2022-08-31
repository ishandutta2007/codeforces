#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int jj = 0; jj < t; jj++){
        char a[9][9];
        for(int i = 0; i < 8; i++){
            cin >> a[i];
        }
        int q,w,e,r;
        q = -1;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(a[i][j] == 'K'){
                    if(q == -1){
                        q =i;
                        w = j;
                    } else {
                        e=i;
                        r=j;
                    }
                    
                }
            }
        }
        if((q-e) % 4 == 0 && (w-r) % 4 == 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}