#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int main(){
    string s;
    cin>>s;
    vector<char> vec;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a')continue;
        vec.push_back(s[i]);
    }
    bool flag=true;
    if(vec.size()%2!=0)flag=false;
    for(int i=0;i<(vec.size()/2);i++){
        if(s[s.length()-i-1]=='a')flag=false;
    }
    for(int i=0;i<(vec.size()/2);i++){
        if(vec[i]!=vec[i+(vec.size()/2)])flag=false;
    }
    if(flag==false)cout<<":(\n";
    else{
        for(int i=0;i<s.length()-vec.size()/2;i++)cout<<s[i];
    }
    return 0;
}