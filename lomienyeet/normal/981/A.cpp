#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1])break;
        if(i==s.length()-2){
            cout<<"0\n";
            return 0;
        }
    }
    bool z=1;
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){
            z=0;
            break;
        }
    }
    cout<<s.length()-z<<"\n";
}