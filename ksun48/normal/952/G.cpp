#include <bits/stdc++.h>
using namespace std;

int main(){
    string f;
    cin >> f;
    int cur = 0;
    for(int j = 0; j < f.size(); j++){
        while(cur != f[j]){
            cur = (cur - 1 + 256) % 256;
            cout << "....." << endl;
            cout << "..X.." << endl;
            cout << ".XXX." << endl;
        }
        cout << "....." << endl;
        cout << ".XX.." << endl;
        cout << ".X..." << endl;
    }
}