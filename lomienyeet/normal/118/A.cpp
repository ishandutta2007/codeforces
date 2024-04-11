#include<bits/stdc++.h>
using namespace std;
string f(string str){
    regex r("[aeiouyAEIOUY]");
    return regex_replace(str, r,"");
}
int main(){
    string s;
    cin>>s;
    string str=f(s);
    char sht;
    for(int i=0;i<str.length();i++){
        sht=tolower(str[i]);
        cout<<"."<<sht;
    }
    return 0;
}