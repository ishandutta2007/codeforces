#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    string s;
    char ch;
    cin>>s>>ch;
    bool ok=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==ch&&i%2==0)ok=1;
    }
    cout<<(ok?"YES\n":"NO\n");
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}