#include <iostream>
using namespace std;

int main() {
    int k, d;
    cin >> k >> d;
    if(d == 0){
        if(k == 1){
            cout << 0 << endl;
        } else {
            cout << "No solution" << endl;
        }
        return 0;
    }
    cout << d;
    for(int i = 1; i < k; i++){
        cout << 0;
    }
    cout << endl;
    return 0;
}