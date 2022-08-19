#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    int a = 0;
    int b = 1023;
    for(int i = 0; i < n; i++){
        string k;
        int z;
        cin >> k >> z;
        if(k[0] == '|'){
            a |= z; b |= z;
        }
        if(k[0] == '&'){
            a &= z; b &= z;
        }
        if(k[0] == '^'){
            a ^= z; b ^= z;
        }
    }
    cout << 3 << endl;
    cout << "| " << (a & b) << endl;
    cout << "& " << (a | b) << endl;
    cout << "^ " << (a & ~b) << endl;
}