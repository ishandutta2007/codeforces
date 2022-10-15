#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int h=stoi(s.substr(0,2)),m=stoi(s.substr(3,2)),ans=0;
    while(h/10!=m%10||h%10!=m/10){
        m++;
        (h+=m/60)%=24;
        m%=60;
        ans++;
    }
    cout<<ans<<"\n";
}