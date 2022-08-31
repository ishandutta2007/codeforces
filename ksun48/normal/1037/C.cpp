#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int num = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) num++;
    }
    int v = 0;
    while(v < s.size()){
        if(s[v] == t[v] || v+1 == s.size() || s[v] == s[v+1] || t[v] == t[v+1]){
            v++;
        } else {
            num--;
            v += 2;
        }
    }
    cout << num << '\n';
}