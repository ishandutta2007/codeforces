#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;string s;
    cin>>n>>s;
    bool z=1;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1]){
            z=0;
            break;
        }
    }
    if(z){
        cout<<n<<"\n";
        return;
    }
    int dx=0,dy=0;
    for(char c:s){
        dx+=(c=='R');
        dy+=(c=='D');
    }
    int ans=0,ptr=n-1;
    for(char c:s){
        if(c=='D'){
            ptr=min(ptr-1,dy-1);
            continue;
        }
        ans+=ptr;
    }
    ans+=ptr;
    ptr=n-1;
    for(char c:s){
        if(c=='R'){
            ptr=min(ptr-1,dx-1);
            continue;
        }
        ans+=ptr;
    }
    ans+=ptr;
    cout<<n*n-ans<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}