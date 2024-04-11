#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int k[a];
    for(int i = 0; i < a; i++) cin >> k[i];
    int r = 0;
    for(int i = 0; i < b; i++) r += k[i];
    int m = r;
    for(int i = b; i < a; i++){
        r += k[i];
        r -= k[i-b];
        m = min(m, r);
    }
    r=0;
    for(int i = 0; i < b; i++) r += k[i];
    if(r == m){
        cout << 1 << endl;
        return 0;
    }
    for(int i = b; i < a; i++){
        r += k[i];
        r -= k[i-b];
        if(r == m){
            cout << i-b+2 << endl;
            return 0;
        }
    }
    return 0;
}