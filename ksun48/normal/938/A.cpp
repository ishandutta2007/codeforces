#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string t = "aeiouy";

int ok(char c){
    for(int j = 0; j < t.size(); j++){
        if(t[j] == c) return 1;
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(i > 0 && ok(s[i]) && ok(s[i-1])) continue;
        cout << s[i];
    }
    cout << endl;
}