#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();i++)a[i]=tolower(a[i]);
    for(int i=0;i<b.length();i++)b[i]=tolower(b[i]);
    if(a>b)cout<<"1\n";
    else if(a<b)cout<<"-1\n";
    else cout<<"0\n";
}