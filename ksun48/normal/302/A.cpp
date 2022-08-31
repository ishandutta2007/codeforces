#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int pos = 0;
    int neg = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 1) pos++;
        else neg++;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if((b-a+1) % 2 == 1){
            cout << 0 << endl;
        } else if((b-a+1)/2 <= pos && (b-a+1)/2 <= neg ){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}