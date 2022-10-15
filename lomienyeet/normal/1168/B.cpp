#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string s;
    cin>>s;
    int ans=0,z=-1;
    for(int i=0;i<s.length();i++){
        for(int j=1;i-(j<<1)>z;j++){
            if(s[i]==s[i-j]&&s[i]==s[i-(j<<1)]){
                z=i-(j<<1);
                break;
            }
        }
        ans+=z+1;
    }
    cout<<ans<<"\n";
}