// i am just doing this to lower my TLE bot virtual solve speed

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;string s;
    cin>>n>>s;
    bool a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R')a=1;
        else if(s[i]=='B')b=1;
        if(s[i]=='W'||i==n-1){
            if(a^b){
                cout<<"NO\n";
                return;
            }
            a=0;
            b=0;
        }
    }
    cout<<"YES\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}