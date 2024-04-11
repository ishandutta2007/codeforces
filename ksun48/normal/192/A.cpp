#include <iostream>

using namespace std;

int main() {
    int k; cin >> k;
    for(int i = 1; i < 45000; i++){
        for(int j = i; j < 45000; j++){
            if(i*(i+1)/2+j*(j+1)/2 == k){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}