#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int fp = 0;
    int num = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == i){
            fp++;
        } else if(a[a[i]] == i){
            num = 2;
        } else if(num == 0){
            num = 1;
        }
    }
    cout << fp + num << endl;
    return 0;
}