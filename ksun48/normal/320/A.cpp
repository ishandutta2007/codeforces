#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char stuff[10];
    cin >> stuff;
    int n = strlen(stuff);
    int a = 0;
    if(stuff[0]!= '1'){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(stuff[i] == '1'){
            a = 1;
        } else if(stuff[i] == '4'){
            a++;
        } else {
            cout << "NO" << endl;
            return 0;
        }
        if(a > 3){
            cout << "NO" << endl;
            return 0;
        }
        
    }
    cout << "YES" << endl;
    return 0;
}