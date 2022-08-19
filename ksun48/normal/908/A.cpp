#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string a;
    cin >> a;
    int num = 0;
    string b = "aeiou13579";
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]) num++;
        }
    }
    cout << num << endl;
}