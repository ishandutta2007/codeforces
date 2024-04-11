#include <iostream>
using namespace std;

int main() {
    int a = -1, b = -1;
    int n;
    cin >> n;
    int r[n];
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }
    for(int i = 0; i < n; i++){
        if(r[i]>0){
            a = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(r[i]<0){
            b = i;
            break;
        }
    }
    if(a != -1){
        cout << 1 << " " << r[b] << endl << 1 << " " << r[a] << endl << n-2;
        for(int i = 0; i < n; i++){
            if(i != a && i != b){
                cout << " " << r[i];
            }
        }
        cout << endl;
    } else {
        cout << 1 << " " << r[b] << endl << 2 << " ";
        int c = -1, d;
        for(int i = 0; i < n; i++){
            if(i != b && r[i] < 0){
                if(c != -1){
                    d = i;
                } else {
                    c = i;
                }
            }
        }
        cout << r[c] << " " << r[d];
        cout << endl << n-3;
        for(int i = 0; i < n; i++){
            if(i != c && i != d && i != b){
                cout << " " << r[i];
            }
        }
        cout << endl;       
    }

    return 0;
}