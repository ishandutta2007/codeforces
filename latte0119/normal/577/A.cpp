#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int ans=0;

    for(int i=1;i<=n;i++){
        if(k%i==0&&k/i<=n)ans++;
    }
    cout<<ans<<endl;
    return 0;
}