#include <bits/stdc++.h>
using namespace std;

string s[2] = {"maomao90","errorgorn"};

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int sum = 0;
        for(int i=0;i<n;i++) {
            int a; cin>>a; sum += a;
        }
        cout<<s[(sum-n)%2]<<'\n';
    }
    return 0;
}