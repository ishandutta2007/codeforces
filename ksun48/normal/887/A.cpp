#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string str;
    cin >> str;
    int ok = 0;
    int n = str.size();
    for(int i = 0; i < n; i++){
        if(str[i] != '1') continue;
        int num = 0;
        for(int j = i + 1; j < n; j++){
            if(str[j] == '0') num++;
        }
        if(num >= 6) ok = 1;
    }
    if(ok) cout << "yes" << endl;
    if(!ok) cout << "no" << endl;
}