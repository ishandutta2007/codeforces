#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string str;
    cin >> str;
    string s1;
    s1 += str[0];
    s1 += str[2];
    s1 += str[4];
    s1 += str[3];
    s1 += str[1];
    LL num = 0;
    for(int i = 0; i < 5; i++){
        num *= 10;
        num += s1[i]-'0';
    }
    LL ans = 1;
    for(int z = 0; z < 5; z++){
        ans = (ans * num) % 100000;
    }
    string g;
    for(int j = 0; j < 5; j++){
        g += (char)(ans % 10 + '0');
        ans /= 10;
    }
    reverse(g.begin(), g.end());
    cout << g << endl;
}