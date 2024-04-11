#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool alphabet[26]={0};
    for(int i=0;i<s.length();i++){
        alphabet[s[i]-'a']=true;
    }
    int cnt=0;
    for(int i=0;i<26;i++){
        if(alphabet[i])cnt++;
    }
    if(cnt%2==0)cout<<"CHAT WITH HER!\n";
    else cout<<"IGNORE HIM!\n";
    return 0;
}