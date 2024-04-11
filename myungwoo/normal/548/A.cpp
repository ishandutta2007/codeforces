#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())

string S; int K;

int main()
{
    cin >> S >> K;
    if (sz(S) % K){ puts("NO"); return 0; }
    int m = sz(S) / K;
    for (int i=0;i<sz(S);i+=m){
        string s = S.substr(i, m);
        for (int j=0;j<sz(s);j++){
            if (s[j] != s[sz(s)-j-1]){ puts("NO"); return 0; }
        }
    }
    puts("YES");
}