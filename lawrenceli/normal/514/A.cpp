#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    for (int i=0; i<s.length(); i++)
        if (i!=0 && s[i]>='5' || i == 0 && s[i]>='5' && s[i]!='9') s[i] = 9-(s[i]-'0')+'0';
    cout << s;
}