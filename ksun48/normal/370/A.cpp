#include <iostream>
using namespace std;
int Abs(int a){
    if(a < 0) return -a;
    return a;
}
int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(r1 == r2 || c1 == c2){
        cout << 1 << " ";
    } else {
        cout << 2 << " ";
    }
    if((r1+c1)%2 == (r2+c2)%2){
        if(r1-c1 == r2-c2 || r1+c1 == r2+c2){
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    } else {
        cout << 0 << " ";
    }
        cout << max(Abs(r1-r2), Abs(c1-c2)) << endl;
    return 0;
}