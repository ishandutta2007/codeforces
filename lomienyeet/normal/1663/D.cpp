#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int n;
    cin>>s>>n;
    for(char&c:s)c=tolower(c);
    if(s=="abc"&&n<2000)cout<<"YES\n";
    else if(s=="arc"&&n<2800)cout<<"YES\n";
    else if(s=="agc"&&n>=1200)cout<<"YES\n";
    else cout<<"NO\n";
}