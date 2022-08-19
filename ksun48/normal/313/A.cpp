#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    if(k > 0){
        cout << k << endl;
        return 0;
    } else {
        k = -k;
        //cout << k << endl;
        cout << max(-(k/10), -(10*(k/100) +k % 10)) << endl;
    }
    
    return 0;
}