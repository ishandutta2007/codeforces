#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    while(s.back()=='0')s.pop_back();
    string t=s;
    reverse(t.begin(),t.end());
    cout<<(s==t?"YES\n":"NO\n");
}