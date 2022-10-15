#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"0\n";
        return 0;
        // please no.
    }
    if(a<b)swap(a,b);
    int ans=1e18,pp=1e18; // long long :prayge:
    vector<int> f;
    for(int i=1;i<=sqrt(a-b);i++){
        if(!((a-b)%i)){
            f.push_back(i);
            f.push_back((a-b)/i);
        }
    }
    for(auto i:f){
        int mini=(b/i+1)*i;
        if(!(b%i))mini=b;
        int k=mini-b,go=(a+k)*(b+k)/gcd(a+k,b+k);
        if(go<pp){
            pp=go;
            ans=k;
        }
        else if(go==pp)ans=min(ans,k);
    }
    cout<<ans<<"\n";
}