#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;cin>>s>>t;
    int a=0,b=0,c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')a++;
        if(t[i]=='1')b++;
        if(s[i]!=t[i])c++;
    }
    if((a-b)%2){
        cout<<"impossible"<<endl;
        return 0;
    }
    c/=2;
    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]==t[i])ans+=s[i];
        else{
            if(c>0)ans+=s[i],c--;
            else ans+=t[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}