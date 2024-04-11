#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int n8 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '8') n8++;
    }
    cout << min(n/11, n8) << endl;
}