#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cin >> c;
            if(c == '1'){
                cout << abs(2-i)+abs(2-j);
                exit(0);
            }
        }
    }
}