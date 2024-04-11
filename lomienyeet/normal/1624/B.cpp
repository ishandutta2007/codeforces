#include <bits/stdc++.h>
using namespace std;
void eat(){
    int a,b,c;
    cin>>a>>b>>c;
    if((a+c)%2==0&&((a+c)/2)%b==0)cout<<"YES\n";
    else if(2*b-a>0&&(2*b-a)%c==0)cout<<"YES\n";
    else if(2*b-c>0&&(2*b-c)%a==0)cout<<"YES\n";
    else cout<<"NO\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}