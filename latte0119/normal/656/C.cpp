#include<bits/stdc++.h>
using namespace std;

signed main(){
    string s;cin>>s;
    int ans=0;
    for(char c:s){
        if(!isalpha(c))continue;
        int a1=('@'<c)&&('['>c);
        int a2=('`'<c)&&('{'>c);
        int idx=c-(isupper(c)?'A':'a')+1;
        ans+=idx*a1-idx*a2;
    }
    cout<<ans<<endl;
}