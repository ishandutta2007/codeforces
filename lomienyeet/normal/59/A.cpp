#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int up=0,low=0;
    for(int i=0;i<s.length();i++){
        if((int)s[i]>=65 and (int)s[i]<=90)up++;
        else low++;
    }
    if(up>low){
        for(int i=0;i<s.length();i++)s[i]=toupper(s[i]);
    }
    else{
        for(int i=0;i<s.length();i++)s[i]=tolower(s[i]);
    }
    cout<<s<<"\n";
    return 0;
}